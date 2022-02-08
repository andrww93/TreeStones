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

const unsigned char DashWave [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x33, 0x33, 0x32, 0xc0, 0xc0, 0xc1, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
void loop() {

  matrix.clear();

 for(int i=7; i>-24 ; i--){

  matrix.clear();
  matrix.drawBitmap(i,0, DashWave, 24,8, LED_RED);//bitmap size parameters are width then height
  matrix.writeDisplay();
  delay(speed);
  
 }
}
