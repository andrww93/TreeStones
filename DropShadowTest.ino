#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
int speed=100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix.begin(0x70);

}

// 'DropTestPos', 48x8px
const unsigned char DropTestPos [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x71, 0xc7, 0xc7, 0x1e, 0x00, 0x10, 0x41, 0x01, 0x04, 
  0x12, 0x00, 0x10, 0x71, 0xc1, 0x07, 0x1e, 0x00, 0x10, 0x40, 0x41, 0x04, 0x14, 0x00, 0x10, 0x71, 
  0xc1, 0x07, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'DropTestPos', 48x8px
const unsigned char DropTestNeg [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0x8e, 0x38, 0x38, 0xe1, 0xff, 0xef, 0xbe, 0xfe, 0xfb, 
  0xed, 0xff, 0xef, 0x8e, 0x3e, 0xf8, 0xe1, 0xff, 0xef, 0xbf, 0xbe, 0xfb, 0xeb, 0xff, 0xef, 0x8e, 
  0x3e, 0xf8, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// 'DropTestShadow', 48x8px
const unsigned char DropTestShadow [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x08, 0x20, 0x20, 0x81, 0x00, 0x08, 0x20, 0x80, 0x82, 
  0x09, 0x00, 0x08, 0x08, 0x20, 0x80, 0x81, 0x00, 0x08, 0x20, 0x20, 0x82, 0x0a, 0x00, 0x08, 0x08, 
  0x20, 0x80, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void loop() {
  // put your main code here, to run repeatedly:

  matrix.clear();

  for (int i=7; i>-48; i--){

    matrix.clear();
    matrix.drawBitmap(i,0,DropTestNeg,48,8,LED_OFF);
    matrix.drawBitmap(i,0,DropTestPos,48,8,LED_YELLOW);
    matrix.drawBitmap(i,0,DropTestShadow,48,8,LED_RED);
    matrix.writeDisplay();
    delay(speed);
  }

}
