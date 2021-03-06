/*
 * main.h
 *
 * Created: 7/2/2020 1:47:20 AM
 *  Author: Angel
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 12000000UL  // 12 MHz
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include "usbdrv.h"
#include "Tables.h"

#define byte uchar
#define uint unsigned int

#define NUM_LOCK 1
#define CAPS_LOCK 2
#define SCROLL_LOCK 4
#define COMPOSE 8
#define KANA 16
#define SHIFT 32

#define	LEFT_CTRL 	1
#define	LEFT_SHIFT 	2
#define	LEFT_ALT 	4
#define	LEFT_GUI 	8
#define	RIGHT_CTRL 	16
#define	RIGHT_SHIFT 32
#define	RIGHT_ALT 	64
#define	RIGHT_GUI	128

#define STATE_WAIT 0
#define STATE_SEND_KEY 1
#define STATE_RELEASE_KEY 2

/* USB report descriptor (length is defined in usbconfig.h)
   This has been changed to conform to the USB keyboard boot
   protocol */
PROGMEM const char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH]
 = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    0x95, 0x05,                    //   REPORT_COUNT (5)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x05, 0x08,                    //   USAGE_PAGE (LEDs)
    0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
    0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x03,                    //   REPORT_SIZE (3)
    0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};

typedef struct {
	uint8_t modifier;
	uint8_t reserved;
	uint8_t keycode[6];
} keyboard_report_t;

static keyboard_report_t keyboard_report; // sent to PC
static uchar protocolVer=1;      /* 0 is the boot protocol, 1 is report protocol */
static volatile uchar LED_state = 0xff; // received from PC
static uchar idleRate; // repeat rate for keyboards
volatile unsigned char RXSerialBuf;  

bool readed = 0;

//mod states
bool ctrlState = false;
bool shiftState = false;
bool altState = false;
bool superState = false;
bool fModState = false;
bool stickyState = false;

//Leds
bool numlock = false;
bool capslock = false;
bool scrolllock = false;
bool composelock = false;
bool kanalock = false;
bool shiftlock = false;

byte ledState = 0;

bool connected = false;
void hardwareInit();
bool sendReport(bool updateNeeded);
bool resetKeys(bool resetNeeded);
void processMods(bool modChanged, byte output);
bool setReport(byte output);
void setLeds(byte set);
void setConnectionState(bool conn);

usbMsgLen_t usbFunctionSetup(uchar data[8]);
usbMsgLen_t usbFunctionWrite(uint8_t * data, uchar len);
void serial_send(unsigned char data);
void serial_init();
void print(char* text, unsigned int len);
void printBin(byte text,uint len);
bool parseKey(byte table, byte key);
bool readPort();
byte swapnibble(byte nib);
byte swapByte(byte b);
int main();

#endif /* MAIN_H_ */
