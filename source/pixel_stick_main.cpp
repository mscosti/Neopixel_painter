/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "pixel_stick_main.h"
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 60
#define WIDTH 20
#define HEIGHT 20
#define WAITTIME 200
#define ROWSIZE WIDTH*3
#define PIXELSINIMAGE WIDTH*HEIGHT*3

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
char aRow[ROWSIZE];
char anImage[PIXELSINIMAGE];
char* helloWorld = "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,58,108,56,86,136,120,131,151,13,39,100,7,35,85,48,71,121,8,31,109,155,161,187,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,38,86,105,108,143,39,70,114,204,209,203,23,43,104,10,41,98,6,39,108,4,43,100,84,106,164,0,21,84,107,115,162,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,113,145,72,83,113,240,238,243,120,122,143,109,131,181,9,39,99,24,34,95,19,50,107,30,56,113,38,63,129,41,60,116,100,114,177,113,124,156,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,152,153,206,209,214,5,33,80,182,186,198,11,44,98,14,40,99,13,45,96,19,31,71,26,55,121,67,91,137,16,45,101,28,50,107,4,23,92,212,219,225,255,252,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,150,153,158,45,49,34,210,180,152,198,185,177,7,16,49,7,45,108,99,109,136,216,218,231,26,52,111,68,92,118,7,38,102,24,51,104,87,102,145,63,73,122,23,28,58,222,223,227,0,0,0,0,0,0,0,0,0,119,120,122,134,140,130,136,130,116,110,96,69,208,184,140,217,200,174,57,67,33,238,238,236,43,71,121,51,70,112,13,37,75,3,29,80,13,36,88,99,108,151,4,20,80,202,208,240,237,242,238,0,0,0,0,0,0,0,0,0,184,185,187,172,172,174,124,118,102,128,106,59,171,141,107,168,182,156,56,78,119,111,124,106,8,40,97,15,38,88,58,79,134,63,87,147,22,44,93,64,82,128,11,30,86,37,52,107,154,161,177,0,0,0,0,0,0,0,0,0,221,221,223,223,223,225,85,108,56,145,154,137,69,98,54,9,49,111,210,218,207,74,103,59,5,30,84,9,37,100,17,37,70,20,46,95,31,52,107,94,111,154,1,12,68,9,26,80,94,112,132,0,0,0,0,0,0,0,0,0,152,151,146,207,207,205,39,45,43,71,115,62,90,123,80,59,83,121,40,64,136,21,60,135,70,118,102,47,68,85,35,49,86,10,37,80,12,25,78,43,63,113,7,22,77,59,63,98,207,217,218,0,0,0,0,0,0,0,0,0,205,205,207,212,208,207,189,189,189,46,88,40,54,91,47,17,50,101,37,103,161,228,223,217,18,49,116,155,178,184,129,151,130,27,59,20,58,88,52,80,78,65,8,20,80,211,192,159,149,144,125,0,0,0,0,0,0,0,0,0,0,0,0,104,109,113,229,229,229,62,76,59,10,26,85,8,35,104,5,27,100,103,126,134,7,27,86,117,167,108,172,201,153,76,113,79,38,63,44,96,142,95,190,170,145,109,93,60,23,38,69,0,0,0,0,0,0,0,0,0,0,0,0,180,178,179,48,70,34,12,25,57,173,179,201,1,16,83,14,35,100,11,35,105,28,49,112,150,192,142,137,162,140,38,82,31,66,103,62,149,174,144,95,113,75,71,76,44,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,43,58,115,8,29,72,87,99,141,2,16,89,6,25,91,11,31,94,211,217,229,192,192,218,62,86,64,55,97,49,42,67,46,79,85,47,140,116,80,197,198,200,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,28,78,23,37,84,140,145,174,18,40,113,7,20,90,14,30,90,6,25,83,44,69,65,66,94,54,77,77,39,142,117,77,20,27,81,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,142,152,179,7,17,79,20,37,83,15,28,83,19,33,82,20,39,97,8,23,78,17,39,80,21,36,55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,56,84,16,32,68,37,52,93,58,69,97,38,54,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0";

void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
void theaterChase(uint32_t c, uint8_t wait);
void theaterChaseRainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void setup() {
//  Serial.println("test");
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
//	testParseString();
	parseString(helloWorld, anImage);
	imageToRows(anImage, aRow);
}

//a testing function
void createDummyRow(int* row){
	int i;
	for(i=0; i<30; i+=3){
		row[i] = 255;
		row[i+1] = 0;
		row[i+2] = 0;
	}
	for(i=30; i<60; i+=3){
		row[i] = 255;
		row[i+1] = 255;
		row[i+2] = 0;
	}
	for(i=60; i<90; i+=3){
		row[i] = 0;
		row[i+1] = 255;
		row[i+2] = 0;
	}
	for(i=90; i<120; i+=3){
		row[i] = 0;
		row[i+1] = 255;
		row[i+2] = 255;
	}
	for(i=120; i<150; i+=3){
		row[i] = 0;
		row[i+1] = 0;
		row[i+2] = 255;
	}
	for(i=150; i<180; i+=3){
		row[i] = 255;
		row[i+1] = 0;
		row[i+2] = 255;
	}
}

//takes a comma deliminated string of RGB values and writes them into one large array containing all the image data
//good idea to pass anImage (global array) for second parameter
void parseString (char* toParse, char* toArray){
	char* savePointer;
	char* token;
	int i;
	while(token = strtok_r(toParse, ",", &savePointer)){
		toArray[i] = (char) atoi(token);
		toParse = savePointer;
		i++;
	}
}

//takes a large array containing all the image data and separates into row sized (60 pixel) array
//good idea to pass anImage (global array) for first parameter and aRow (global array) for second parameter
void imageToRows(char* imageArray, char* rowArray){
	int i;
	for(i=0;i<HEIGHT;i++){
		rowArray = imageArray + i*ROWSIZE;
		displayLine(rowArray);
	}
}

//a testing function
void testParseString(){
	char* toParse = "255,0,0,0,255,0,0,0,255,255,255,0,255,0,255,0,255,255";
	parseString(toParse, anImage);
}

//turns off all the pixels
void clearPixels(){
	uint32_t black = strip.Color(0,0,0);
	int i;
	for(i=0; i<NUMPIXELS; i++){
		strip.setPixelColor(i, black);
	}
	strip.show();
}

//takes in a row-sized (60 pixel) array and tells the pixel stick to display those colors
//good idea to pass in aRow (global array) as parameter
void displayLine(char* row){
	int pixelIndex;
	int colorIndex = 0;
	uint32_t color;
	for(pixelIndex=0; pixelIndex<WIDTH; pixelIndex++){
		color = strip.Color((row[colorIndex]), (row[colorIndex+1]), (row[colorIndex+2]));
		strip.setPixelColor(pixelIndex, color);
		colorIndex += 3;
	}
	strip.show();
	delay(WAITTIME);
	clearPixels();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

