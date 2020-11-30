#include "main.h"

//Fuses: -U lfuse:w:0xee:m -U hfuse:w:0xd9:m -U efuse:w:0xff:m 

int main() {
	bool updateNeeded = false;
	bool resetNeeded = false;
	int flashCounter = 0;
	int idleCounter = 0;
	int sendCounter = 0;
	/*
	 Pin descriptions
	 PB0..PB7 Keyboard Matrix
	 PD0 Test Point 1
	 PD1 Test Point 2
	 PD2 D+
	 PD3 D-
	 PD4 Scroll Lock LED
	 PD5 Num Lock LED
	 PD6 Caps Lock LED
	 */

	hardwareInit();

	print("Boot!\n\r", 7);

	//main loop
	while (1) {
		wdt_reset(); // keep the watchdog happy
		usbPoll();

		//check if still connected
		if(usbInterruptIsReady() && connected) idleCounter = 0;
		else if(!usbInterruptIsReady() && connected)idleCounter++;
		if(idleCounter > 5000){
			idleCounter = 0;
			setConnectionState(false);
		}

		//send packet every so often to make sure we are still connected
		if (sendCounter++ == 10000) {
			byte tmp[1] = {0};
			usbSetInterrupt(tmp, 1);
			sendCounter = 0;
		}

		if (connected) {
			setLeds(ledState);
			updateNeeded = readPort();
			/* If an update is needed, send the report */
			if (sendReport(updateNeeded)) {
				updateNeeded = false;
				resetNeeded = true;
			}
			//If the package has been sent and the keys need clearing, clear them.
			if (resetKeys(resetNeeded)) {
				resetNeeded = false;
			}
		} else {
			//not connected, flash the leds
			if (flashCounter++ == 10000) {
				PORTD ^= (1 << PORTD4);
				PORTD ^= (1 << PORTD5);
				PORTD ^= (1 << PORTD6);
				flashCounter = 0;
			}
		}
	}

	return 0;
}

//Initializa the hardware
void hardwareInit(){
	DDRB = 0x00; //Set PortB as input
	DDRD = ~USBMASK; //Set All pins as output Except USB

	for (int i = 0; i < sizeof(keyboard_report); i++) { // clear report initially
		((uchar*) &keyboard_report)[i] = 0;
	}

	wdt_enable(WDTO_1S); // enable 1s watchdog timer

	usbInit();

	usbDeviceDisconnect(); // enforce re-enumeration
	for (int i = 0; i < 250; i++) { // wait 500 ms
		wdt_reset(); // keep the watchdog happy
		_delay_ms(2);
	}
	usbDeviceConnect();

	sei(); // Enable interrupts after re-enumeration

	serial_init(); //Init Uart
}

//send the pressed keys to the computer
bool sendReport(bool updateNeeded) {
	//send report if last report was already sent
	if (updateNeeded && usbInterruptIsReady()) {
		usbSetInterrupt((void*) &keyboard_report, sizeof(keyboard_report));
		return true;
	}
	return false;
}

//clear the the pressed keys and send the HID report
bool resetKeys(bool resetNeeded) {
	if (resetNeeded && usbInterruptIsReady()) {
		//clear keycode array
		for (int i = 0; i < 6; i++) {
			if (keyboard_report.keycode[i])
				keyboard_report.keycode[i] = 0;
		}
		//If not in sticky mode, clear the modifiers
		if (!stickyState) {
			keyboard_report.modifier = 0;
		}
		//send report
		usbSetInterrupt((void*) &keyboard_report, sizeof(keyboard_report));
		return true;
	}
	return false;
}

//read the matrix and put the bits in the right order
bool readPort() {

	byte portState = PINB;
	//look at trigger pin
	bool trigger = !(portState & (1));
	//if triggerd and value not processed yet
	if (trigger && !readed) {
		//look in which array to look
		bool ctrl = !(portState & (1 << PINB1));
		bool shft = !(portState & (1 << PINB2));
		bool othr = !(portState & (1 << PINB3));
		byte all = ctrl * 4 + shft * 2 + othr * 1;
		//read the rest for the key value
		byte key = swapnibble((portState & 0xF0) >> 4);
		readed = true;
		return parseKey(all, key);
	}
	if (!trigger && readed) {
		//trigger was released
		readed = false;
	}
	return false;
}

//parse what key was pressed on the keyboard
bool parseKey(byte table, byte key) {
	byte output = 0; //stores the output byte
	bool modChanged = false; //stores if a modifier was changed (for sticky mode)
	//fmod shifts to different for f1-f24 keys and stuff
	//if output is set to 0xFF, it means that a modifier was pressed

	switch (table) {
	case 0:
		//lower case upper
		if (key > 10 && key != 15 && !fModState) shiftState = true;
		output = fModState ? pgm_read_byte(&FLowr2[key]) : pgm_read_byte(&Lowr2[key]);
		if (key == 15) {
			//if the key is CNTR, set the CTRL key state
			ctrlState = !ctrlState;
			modChanged = true;
			output = 0xff;
		}
		break;
	case 1:
		//lower case lower
		output = fModState ? pgm_read_byte(&FLowr1[key]) : pgm_read_byte(&Lowr1[key]);
		break;
	case 2:
		//higher case upper
		shiftState = true;
		if (key > 10 && !fModState) shiftState = false;
		output = fModState ? pgm_read_byte(&FUppr2[key]) : pgm_read_byte(&Uppr2[key]);
		break;
	case 3:
		//higher case lower
		shiftState = true;
		output = fModState ? pgm_read_byte(&FUppr1[key]) : pgm_read_byte(&Uppr1[key]);
		break;
	case 4:
		//numbers
		shiftState = false;
		if ((key == 10 || key == 12 || key >= 14) && !fModState)
			shiftState = true;
		output = fModState ? pgm_read_byte(&FNumbr[key]) : pgm_read_byte(&Numbr[key]);
		break;
	case 5:
		//symbols
		shiftState = true;
		if ((key == 0 || key == 7 || key >= 12) && !fModState)
			shiftState = false;
		output = fModState ? pgm_read_byte(&FSymbl[key]) : pgm_read_byte(&Symbl[key]);
		break;
	case 6:
		//Ctrl Num and Ctrl Letter upper and special keys
		shiftState = false;
		output =
				fModState ? pgm_read_byte(&FCtrl1[key]) : pgm_read_byte(&Ctrl1[key]);
		if (key == 12) {
			//if the key pressed was TRANS, set fmod state
			fModState = !fModState;
			output = 0xff;
		} else if (key == 8){
			//if White key was pressed, enable sticky mode
			stickyState = !stickyState;
		}
		break;
	case 7:
		//Ctrl Shift num and Ctrl Letter lower and special keys
		shiftState = false;
		output = fModState ? pgm_read_byte(&FCtrl2[key]) : pgm_read_byte(&Ctrl2[key]);
		if (key == 1) {
			//if CHAN key was pressed, set Super y state
			superState = !superState;
			modChanged = true;
			output = 0xff;
		} else if (key == 4) {
			//if ALPHA key was pressed, set alt state.
			altState = !altState;
			modChanged = true;
			output = 0xff;
		} else if (key == 5 || key == 6 || key == 7 || key == 12) {
			// if top color keys were pressed,change the meaning of the leds
			if(key == 5){
				//Black key
				//LEDs are NumLock, Capslock, ScrollLock
				ledState = 0;
			}
			else if(key == 6){
				//Red key
				//LEDs are Ctrl, Alt, Super
				ledState = 1;
			}
			else if(key == 12){
				//Yellow key
				//LEDs are Shift(kinda), fMod, Sticky
				ledState = 2;
			}
			else{
				//Green key (basically useless)
				//LEDs are Compose, Kana, ShiftLock
				ledState = 3;
			}
			output = 0xFF;
		}
		break;
	default:
		print("No Key!\r\n", 9);
		return false;
		break;
	}
	//process the modifiers
	processMods(modChanged,output);

	//set the keyboard report
	return setReport(output);
}

//process the key modifiers
void processMods(bool modChanged, byte output){

	if (superState) {
		if (!stickyState || modChanged) {
			keyboard_report.modifier += LEFT_GUI;
		}
	} else {
		if (keyboard_report.modifier & LEFT_GUI) {
			keyboard_report.modifier -= LEFT_GUI;
		}
	}

	if (ctrlState) {
		if(!stickyState || modChanged){
			keyboard_report.modifier += LEFT_CTRL;
		}
	} else {
		if (keyboard_report.modifier & LEFT_CTRL) {
			keyboard_report.modifier -= LEFT_CTRL;
		}
	}
	if (shiftState) {
		if (!(keyboard_report.modifier & LEFT_SHIFT)){
			keyboard_report.modifier += LEFT_SHIFT;
		}
	} else {
		if (keyboard_report.modifier & LEFT_SHIFT) {
			keyboard_report.modifier -= LEFT_SHIFT;
		}
	}

	if (altState) {
		if (!stickyState || modChanged) {
			keyboard_report.modifier += LEFT_ALT;
		}
	} else {
		if (keyboard_report.modifier & LEFT_ALT) {
			keyboard_report.modifier -= LEFT_ALT;
		}
	}

	//if key wasn't a modifier, set the modifiers to false;
	if (output != 0xFF) {
		if(!stickyState){
			ctrlState = false;
			altState = false;
			superState = false;
			fModState = false;
		}
		shiftState = false;
	}
}

//create the keyboard report
bool setReport(byte output){
	//if key was valid and not a mod
	if (output != 0x00 && output != 0xFF) {
			//loop through array to find a place for keycode;
			for (int i = 0; i < 6; i++) {
				//return if its already in the array
				if(keyboard_report.keycode[i] == output){
					return true;
				}
				//if there is nothing at location, set to the keycode
				if (keyboard_report.keycode[i] == 0) {
					keyboard_report.keycode[i] = output;
					return true;
				}
			}
			//if there was no place left, send error to computer.
			keyboard_report.keycode[0] = KEY_errorRollOver;
		}
		//if key was a modifier, send the modifiers
		if(output == 0xFF){
			return true;
		}
		//invalid key was pressed;
		return false;
}

//set the meaning of the LEDs
void setLeds(byte set) {
	//set the meaning of the leds;
	bool val1 = false;
	bool val2 = false;
	bool val3 = false;
	switch (set) {
	case 0:
		val1 = numlock;
		val2 = capslock;
		val3 = scrolllock;
		break;
	case 1:
		val1 = ctrlState;
		val2 = altState;
		val3 = superState;
		break;
	case 2:
		val1 = shiftState;
		val2 = fModState;
		val3 = stickyState;
		break;
	case 3:
		val1 = composelock;
		val2 = kanalock;
		val3 = shiftlock;
		break;
	}
	if (val1) {
		PORTD |= (1 << PORTD5);
	} else {
		PORTD &= ~(1 << PORTD5);
	}

	if (val2) {
		PORTD |= (1 << PORTD6);

	} else {
		PORTD &= ~(1 << PORTD6);
	}

	if (val3) {
		PORTD |= (1 << PORTD4);
	} else {
		PORTD &= ~(1 << PORTD4);
	}

}

//Set the USB connection state
void setConnectionState(bool conn){
	//return if connection state didn't change
	if(conn == connected) return;
	else{
		if(conn){
			print("Connected!\n\r", 12);
			connected = true;
		}
		else{
			print("Disconnected!\n\r", 15);
			setLeds(4); //black out the leds so the can flash in sync
			connected = false;
		}
	}
}
/////////////////////////////////////
///////   SERIAL FUNCTIONS   ////////
/////////////////////////////////////

//initialize the serial registers
void serial_init() {
	// initialize USART
	UBRRL = UBRR_VALUE & 255;
	UBRRH = UBRR_VALUE >> 8;
	UCSRB = ((1 << TXEN) | (1 << RXEN) | (1 << RXCIE)); // fire-up USART
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0); // fire-up USART
	serial_send(0);
	serial_send('\n'); //send carriage return
	serial_send('\r');
	serial_send(0);
}

// send a single byte via USART
void serial_send(byte data) {
	while (!(UCSRA & (1 << UDRE))) {
	}; //wait while previous byte is completed
	UDR = data; // Transmit data
}

//receive one byte from uart
uint8_t USART_ReceiveByte() {
	while ((UCSRA & (1 << RXC)) == 0)
		;
	return UDR;
}

//check if there is data in the serial buffer
bool serialAvailible() {
	return (UCSRA & (1 << RXC));
}

//print some text or stuff
void print(char *text, uint len) {
	//loop and send each character
	for (uint i = 0; i <= len; i++) {
		serial_send(text[i]);
	}
	serial_send(0);//null terminate
}

//print value as binary
void printBin(byte text, uint len) {
	for (uint i = 0; i < len; i++){
		serial_send((text & 0x1 << i) ? '1' : '0');
	}
	serial_send(0);
}

//ISR(USART_RX_vect){RXSerialBuf = UDR}

/////////////////////////////////////
///////    HELP FUNCTIONS    ////////
/////////////////////////////////////

//swap some bits around to fix a mistake i made in the prototype (I don't feel like re-writing the arrays)
byte swapnibble(byte nib) {
	bool A = nib & (1 << 0);
	bool B = nib & (1 << 1);
	bool C = nib & (1 << 2);
	bool D = nib & (1 << 3);
	return D * 1 + C * 2 + B * 4 + A * 8;
}
////////////////////////////////////
///////    USB FUNCTIONS    ////////
////////////////////////////////////

//this gets called whenever the computer sends data
usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	setConnectionState(true);
	usbRequest_t *rq = (void*) data;
	if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) {
		switch (rq->bRequest) {
		case USBRQ_HID_GET_REPORT: // send keys pressed if asked here
			// wValue: ReportType (highbyte), ReportID (lowbyte)
			usbMsgPtr = (void*) &keyboard_report; // we only have this one
			return sizeof(keyboard_report);
		case USBRQ_HID_SET_REPORT: // if wLength == 1, should be LED state
			return (rq->wLength.word == 1) ? USB_NO_MSG : 0;
		case USBRQ_HID_GET_IDLE: // send idle rate to PC as required by spec
			usbMsgPtr = &idleRate;
			return 1;
		case USBRQ_HID_SET_IDLE: // save idle rate as required by spec
			idleRate = rq->wValue.bytes[1];
			return 0;
		case USBRQ_HID_GET_PROTOCOL:
			protocolVer = rq->wValue.bytes[1];
			return 0;
		case USBRQ_HID_SET_PROTOCOL:
			usbMsgPtr = &protocolVer;
			return 1;
		}
	}

	return 0; // by default don't return any data
}

//this is used to set the keyboard led state
usbMsgLen_t usbFunctionWrite(uint8_t *data, uchar len) {

	if (data[0] == LED_state)
		return 1;
	else
		LED_state = data[0];

	// LED state changed
	numlock = (LED_state & NUM_LOCK);
	capslock = (LED_state & CAPS_LOCK);
	scrolllock = (LED_state & SCROLL_LOCK);
	composelock = (LED_state & COMPOSE);
	kanalock = (LED_state & KANA);
	shiftlock = (LED_state & SHIFT);

	return 1; // Data read, not expecting more
}
