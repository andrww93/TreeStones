#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

int speed=100;

//////////FRAMES//////////////////////////////

const unsigned char shockFrames[] [10] PROGMEM = {

  // 'ShockFrame1, 8x8px

{ 0x81, 0x42, 0x42, 0x24, 0x24, 0x42, 0x42, 0x81
}, 
  // 'ShockFrame2, 8x8px

{ 0x42, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x42
}, 
  // 'ShockFrame3, 8x8px

{ 0x24, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x24
}, 
  // 'ShockFrame4, 8x8px

{ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18
}, 
  // 'ShockFrame5, 8x8px

{ 0x18, 0x18, 0x18, 0x24, 0x24, 0x18, 0x18, 0x18
}, 
  // 'ShockFrame6, 8x8px

{ 0x18, 0x24, 0x24, 0x42, 0x42, 0x24, 0x24, 0x18
}, 
  // 'ShockFrame7, 8x8px

{ 0x24, 0x42, 0x42, 0x81, 0x81, 0x42, 0x42, 0x24
}, 
  // 'ShockFrame8, 8x8px

{ 0x42, 0x81, 0x81, 0x00, 0x00, 0x81, 0x81, 0x42
}, 
  // 'ShockFrame9, 8x8px

{ 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81
}, 
  // 'ShockFrame10, 8x8px

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}
};

////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix.begin(0x70);
}

void Shock(){

  for(int i=0;i<10;i++){
    matrix.clear();
    
    //have to draw bitmap twice since this animation is 8x8
    matrix.drawBitmap(0,0,shockFrames[i],8,8,LED_RED);

    //need to swap the 0 and 8 if rotation setting is 1
    matrix.drawBitmap(0,8,shockFrames[i],8,8,LED_RED);

    matrix.writeDisplay();
    delay(speed);
  }

  for(int i=9;i>-1;i--){
      matrix.clear();
    
    //have to draw bitmap twice since this animation is 8x8
    matrix.drawBitmap(0,0,shockFrames[i],8,8,LED_RED);

    //need to swap the 0 and 8 if rotation setting is 1
    matrix.drawBitmap(0,8,shockFrames[i],8,8,LED_RED);

    matrix.writeDisplay();
    delay(speed);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  matrix.setRotation(0);

  //if you use setRotation(1), you need to swap the 0 and 8 in the second drawBitmap line of the function
  //matrix.setRotation(1);
  Shock();
}
