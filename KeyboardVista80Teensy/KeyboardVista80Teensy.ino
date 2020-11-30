#include "Keyboard.h"
#include "Tables.h"

bool ctrlState = 0;
bool shiftState = 0;
bool altState = 0;
bool superState = 0;
bool fModState = 0;

void setup() {
  // put your setup code here, to run once:
DDRB = B00000000;
pinMode(0,INPUT);
Serial.begin(115200);
}

bool readed = false;
void loop() {
  // put your main code here, to run repeatedly:
  bool pinState = digitalRead(0);
  if(!pinState && !readed){
    byte portState = PINB;
    bool ctrl = !((portState >> 6)  & 0x01);
    bool shft = !((portState >> 5)  & 0x01);
    bool othr = !((portState >> 4)  & 0x01);
    byte all =  ~(portState >> 4) & B0111;
    byte key = portState&B00001111;
    if(ctrl){
      Serial.print("CTRL ");
    }
    else{
      Serial.print("     ");
    }
    if(shft){
      Serial.print("SHFT ");
    }
    else{
      Serial.print("     ");
    }
    if(othr){
      Serial.print("OTHR ");
    }
    else{
      Serial.print("     ");
    }
    Serial.print("PORTB: ");
    Serial.print(portState);
    //Serial.print(" CHAR: ");
    //Serial.print((portState&B00011111 + 64));
    Serial.print(" ALL: ");
    Serial.print(all, BIN);
    Serial.print(" BIN: ");
    Serial.println(portState, BIN);

    parseKey(all,key);
    
    readed = true;
  }
  if(pinState && readed){
    readed = false;
  }
  

}

void parseKey(byte table, byte key){
  char output = 0;
    
    switch(table){
      case 0:
        //lower case upper
        Serial.print("(LCU) ");
        output = fModState?FLowr2[key]:Lowr2[key];
        if(key == 15){
          ctrlState?Keyboard.release(0x80):Keyboard.press(0x80);
          ctrlState = !ctrlState;
          output = 0xff;
        }
        break;
      case 1:
        //lower case lower
        Serial.print("(LCL) ");
        output = fModState?FLowr1[key]:Lowr1[key];
        break;
      case 2:
        //higher case upper
        Serial.print("(HCU) ");
        output = fModState?FUppr2[key]:Uppr2[key];
        break;
      case 3:
        //higher case lower
        Serial.print("(HCL) ");
        output = fModState?FUppr1[key]:Uppr1[key];
        break;
      case 4:
        //numbers
        Serial.print("(NUM) ");
        output = fModState?FNumbr[key]:Numbr[key];
        break;
      case 5:
        //symbols
        Serial.print("(SYM) ");
        output = fModState?FSymbl[key]:Symbl[key];
        break;
      case 6:
        //Ctrl Num and Ctrl Letter upper and special keys
        Serial.print("(CTRL1) ");
        output = fModState?FCtrl1[key]:Ctrl1[key];
        if(key == 0){
          superState?Keyboard.release(0x83):Keyboard.press(0x83);
          superState = !superState;
          output = 0xff;
        }
        else if(key == 12){
          fModState = !fModState;
          output = 0xff;
        }
        break;
      case 7:
        //Ctrl Shift num and Ctrl Letter lower and special keys
        Serial.print("(CTRL2) ");
        output = fModState?FCtrl2[key]:Ctrl2[key];
        if(key == 1){
          shiftState?Keyboard.release(0x81):Keyboard.press(0x81);
          shiftState = !shiftState;
          output = 0xff;
        }
        else if(key == 4){
          altState?Keyboard.release(0x82):Keyboard.press(0x82);
          altState = !altState;
          output = 0xff;
        }
        else if(key == 5){
        }
        break;
    }
    Serial.println(output,HEX);
    Keyboard.write(output);
    if(output != 0xFFFFFFFF){
      ctrlState = 0;
      shiftState = 0;
      altState = 0;
      superState = 0;
      Keyboard.releaseAll();
      fModState = 0;
    }
}
