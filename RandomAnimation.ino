#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

int speed=100;
int wordSelect=0;
int animationSelect=0;
int wordDirection=0;

String word0="Rhizome";
String word1="Spike";
String word2="Cactus";

String tempWord="";




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix.begin(0x70);  // pass in the address
}


///////BURST FRAMES/////////////////////////////////////
// 'Frame1Red', 8x8px
const unsigned char Frame1Red [] PROGMEM = {
  0xe7, 0xff, 0xff, 0x7e, 0x7e, 0xff, 0xff, 0xe7
};

// 'Frame2Red', 8x8px
const unsigned char Frame2Red [] PROGMEM = {
  0xc3, 0xe7, 0x7e, 0x3c, 0x3c, 0x7e, 0xe7, 0xc3
};

// 'Frame3Red', 8x8px
const unsigned char Frame3Red [] PROGMEM = {
  0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81
};

// 'Frame3Green', 8x8px
const unsigned char Frame3Yellow [] PROGMEM = {
  0x18, 0x00, 0x00, 0x81, 0x81, 0x00, 0x00, 0x18
};

// 'Frame4Yellow', 8x8px
const unsigned char Frame4Yellow [] PROGMEM = {
  0x3c, 0x18, 0x81, 0xc3, 0xc3, 0x81, 0x18, 0x3c
};

// 'Frame5Yellow', 8x8px
const unsigned char Frame5Yellow [] PROGMEM = {
  0x7e, 0xbd, 0xdb, 0xe7, 0xe7, 0xdb, 0xbd, 0x7e
};

// 'Frame6Yellow', 8x8px
const unsigned char Frame6Yellow [] PROGMEM = {
  0xe7, 0xff, 0xff, 0x7e, 0x7e, 0xff, 0xff, 0xe7
};
////////////////////////////////////////////////////


/////WIPE FRAMES///////////////////////////////////
const unsigned char wipeFrames[][16] PROGMEM = {

  // 'WipeFrame1, 16x8px

{ 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01
}, 
  // 'WipeFrame2, 16x8px

{ 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03
}, 
  // 'WipeFrame3, 16x8px

{ 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07
}, 
  // 'WipeFrame4, 16x8px

{ 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e
}, 
  // 'WipeFrame5, 16x8px

{ 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c
}, 
  // 'WipeFrame6, 16x8px

{ 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38
}, 
  // 'WipeFrame7, 16x8px

{ 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70
}, 
  // 'WipeFrame8, 16x8px

{ 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0
}, 
  // 'WipeFrame9, 16x8px

{ 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0
}, 
  // 'WipeFrame10, 16x8px

{ 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80
}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////


////BLAST FRAMES//////////////////////////////////////////////////////////////////////////////////////////
const unsigned char blastFrames[] [16] PROGMEM = {

  // 'BlastFrame1, 16x8px

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}, 
  // 'BlastFrame2, 16x8px

{ 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00
}, 
  // 'BlastFrame3, 16x8px

{ 0x00, 0x00, 0x07, 0xe0, 0x07, 0xe0, 0x06, 0x60, 0x06, 0x60, 0x07, 0xe0, 0x07, 0xe0, 0x00, 0x00
}, 
  // 'BlastFrame4, 16x8px

{ 0x00, 0x00, 0x0f, 0xf0, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0f, 0xf0, 0x00, 0x00
}, 
  // 'BlastFrame5, 16x8px

{ 0x00, 0x00, 0x1f, 0xf8, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1f, 0xf8, 0x00, 0x00
}, 
  // 'BlastFrame6, 16x8px

{ 0x00, 0x00, 0x3f, 0xfc, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x3f, 0xfc, 0x00, 0x00
}, 
  // 'BlastFrame7, 16x8px

{ 0x00, 0x00, 0x7f, 0xfe, 0x78, 0x1e, 0x78, 0x1e, 0x78, 0x1e, 0x78, 0x1e, 0x7f, 0xfe, 0x00, 0x00
}, 
  // 'BlastFrame8, 16x8px

{ 0x00, 0x00, 0x7f, 0xfe, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x7f, 0xfe, 0x00, 0x00
}, 
  // 'BlastFrame9, 16x8px

{ 0x00, 0x00, 0x7f, 0xfe, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x7f, 0xfe, 0x00, 0x00
}, 
  // 'BlastFrame10, 16x8px

{ 0x00, 0x00, 0x7f, 0xfe, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x7f, 0xfe, 0x00, 0x00
}, 
  // 'BlastFrame11, 16x8px

{ 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xff, 0xff
}, 
  // 'BlastFrame12, 16x8px

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

void Wipe(){


  //if you dont reset rotation, animation may only play on one side of the matrix
  matrix.setRotation(1);
  
  for(int i=0; i<3;i++){
  
    for(int k=0;k<10;k++){
      matrix.clear();
      matrix.drawBitmap(0,0,wipeFrames[k],16,8,LED_RED);        
      matrix.writeDisplay();
      delay(speed);
    }
  }

}

void Blast(){


  //if you dont reset rotation, animation may only play on one side of the matrix
  matrix.setRotation(1);
  
  for(int i=0; i<3;i++){
  
    for(int k=0;k<10;k++){
      matrix.clear();
      matrix.drawBitmap(0,0,blastFrames[k],16,8,LED_RED);        
      matrix.writeDisplay();
      delay(speed);
    }
  }

}

void Burst(){

  //if you dont reset rotation, animation may only play on one side of the matrix
  matrix.setRotation(0);


//animation will loop 10 times, change i< value to change amount of loops
for(int i=0;i<15;i++){
  

   //frame 1
  matrix.clear();
  matrix.drawBitmap(0,0, Frame1Red, 8, 8, LED_RED);
  matrix.drawBitmap(0,8, Frame1Red, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(speed);
  
  //frame 2
  matrix.clear();
  matrix.drawBitmap(0,0, Frame2Red,8,8,LED_RED);
  matrix.drawBitmap(0,8, Frame2Red,8,8,LED_RED);
  matrix.writeDisplay();
  delay(speed);

  //frame 3
  matrix.clear();
  matrix.drawBitmap(0,0, Frame3Red,8,8,LED_RED);
  matrix.drawBitmap(0,8, Frame3Red,8,8,LED_RED);
  matrix.writeDisplay();
  delay(speed);

  //frame4
  matrix.clear();
  matrix.drawBitmap(0,0,Frame3Yellow,8,8,LED_RED);
  matrix.drawBitmap(0,8,Frame3Yellow,8,8,LED_RED);
  matrix.writeDisplay();
  delay(speed);

  //frame5
  matrix.clear();
  matrix.drawBitmap(0,0,Frame4Yellow,8,8,LED_RED);
  matrix.drawBitmap(0,8,Frame4Yellow,8,8,LED_RED);
  matrix.writeDisplay();
  delay(speed);

  //frame6
  matrix.clear();
  matrix.drawBitmap(0,0,Frame5Yellow,8,8,LED_RED);
  matrix.drawBitmap(0,8,Frame5Yellow,8,8,LED_RED);
  matrix.writeDisplay();
  delay(speed);

  return;

}
  
}

void writeTextHorizontal(String text){
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  //fine tune the X> value to set how long the loop goes, can cut off the word, or have a blank period after word scrolls
  for (int8_t x=0; x>=-34; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(text);
    matrix.writeDisplay();
    delay(100);
  }
}

void writeTextVertical(String text){
  matrix.setTextSize(2);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(0);
  for (int8_t x=0; x>=-34; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(text);
    matrix.writeDisplay();
    delay(100);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  //the upper bound on the random number has to be 1 higher then the number of options
  wordSelect=int(random(0,3));
  wordDirection=int(random(0,2));
  
  if(wordSelect==0)
    tempWord=word0;
  else if(wordSelect==1)
    tempWord=word1;
  else if(wordSelect==2)
    tempWord=word2;


  if(wordDirection==0)
   writeTextHorizontal(tempWord);
  else if(wordDirection==1)
    writeTextVertical(tempWord);
    
 animationSelect=int(random(0,3));

 if(animationSelect==0)
  Blast();
 else if(animationSelect==1)
  Burst();
 else if(animationSelect==2)
  Wipe();  
}
