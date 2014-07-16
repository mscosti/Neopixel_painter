/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "pixel_stick_main.h"
#include "imagereader.h"
#include <Adafruit_NeoPixel.h>
#include <SD.h>

#define PIN 6
#define NUMPIXELS 60
#define WIDTH 3
#define HEIGHT 2
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
ImageReader imageReader = ImageReader();

int aRow[ROWSIZE];
int anImage[PIXELSINIMAGE];
String inputString = "";
boolean stringComplete = false;


void setup() {
	Serial.begin(9600);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
	pinMode(10, OUTPUT);

	// check to make sure the SD card in all set
	if (!SD.begin(10)) {
		Serial.println("initialization failed!");
		return;
	}
	Serial.println("initialization done.");

	// test to print one row of the image
	printImageRow();
}

void loop() {
//	Serial.println("test");
//	parseString(helloWorld, anImage);
//	imageToRows(anImage, aRow);
//	Serial.println("nope\n");
//	if (stringComplete) {
//		 Serial.println(inputString); 
//		 // clear the string:
//		 inputString = "";
//		 stringComplete = false;
//	  }


}

void serialEvent() {
	while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}


// A test to both load an image and print out the first
// row of RGB values of the image
void printImageRow(){

// load an image.  For now, pick redbox.bmp by default
	imageReader.loadImage("/redbox.bmp");
	Serial.print("Width: ");
	Serial.println(imageReader.width);
	Serial.print("Height: ");
	Serial.println(imageReader.width);
	
	// create a row initialized to the rowStep of the image
	uint8_t row[imageReader.rowStep];
	
	// read the next row into the row array
	imageReader.readNextRow(row);
	
	// print out the RGB values for the whole row
	for (int i = 0; i < imageReader.rowStep; i+=3){
		Serial.print("R: ");
		Serial.print(row[i+2]);
		Serial.print("\tG: ");
		Serial.print(row[i+1]);
		Serial.print("\tB: ");
		Serial.println(row[i]);
	}
	
}
//takes a comma deliminated string of RGB values and writes them into one large array containing all the image data
//good idea to pass anImage (global array) for second parameter
void parseString (char* toParse, int* toArray){
	char* savePointer;
	char* token;
	int i;
	while(token = strtok_r(toParse, ",", &savePointer)){
		toArray[i] = atoi(token);
		toParse = savePointer;
		i++;
	}
}

//takes a large array containing all the image data and separates into row sized (60 pixel) array
//good idea to pass anImage (global array) for first parameter and aRow (global array) for second parameter
void imageToRows(int* imageArray, int* rowArray){
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
void displayLine(int* row){
	int pixelIndex;
	int colorIndex = 0;
	uint32_t color;
	for(pixelIndex=0; pixelIndex<WIDTH; pixelIndex++){
		color = strip.Color(row[colorIndex], row[colorIndex+1], row[colorIndex+2]);
		strip.setPixelColor(pixelIndex, color);
		colorIndex += 3;
	}
	strip.show();
	delay(WAITTIME);
	clearPixels();
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
