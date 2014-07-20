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
#define MAXPICTURES 20
#define WAITTIME 50


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
ImageReader imageReader = ImageReader();

String pictures[MAXPICTURES];
File root;

void setup() {
	Serial.begin(9600);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
	pinMode(10, OUTPUT);

	// check to make sure the SD card is all set
	if (!SD.begin(10)) {
		Serial.println("initialization failed!");
		return;
	}
	Serial.println("initialization done.");
	
	// open root for accessing all files 
	root = SD.open("/");
	
}

void loop() {

	// Print out all files from root
	int numImgs = printDirectory(root,0);
	
	// buffer to put the selected image into
	char selectedImage[13];
	
	// wait for image selection from user over serial
	imageSelect(numImgs,selectedImage);
	
	// display the image
	displayPic(selectedImage);
	
}

/*
	Waits for the user to select an image,
	and returns the filename of the selected
	int the passed in buffer.
	
	@param int numImgs: number of images to select from
	@param char* fileBuff: the buffer to put the filename in
*/
void imageSelect(int numImgs,char* fileBuff){
	
	Serial.println("\n");
	Serial.println("Select one of the images above");
	
	// wait until serial is available
	while(!Serial.available()){}
	
	// serial data recieved, continue
	int img = Serial.parseInt();
	Serial.println(img);
	
	if ((img <= numImgs) && (0 <= img)){
		
		pictures[img].toCharArray(fileBuff,13);
		Serial.println(fileBuff);
	}
	else {
		Serial.println("do not compute");
	}
}

/*
	loads the image given, and displays it on the 
	pixel stick row by row
	
	@param char* imgFile: the bitmap image file to display
*/
void displayPic(char* imgFile) {
	// load the image into the imageReader
	imageReader.loadImage(imgFile);
	
	// create a row initialized to the rowStep of the image
	uint8_t row[imageReader.rowStep];
	
	for (int i = 0; i < imageReader.height; i++){
		// read the next row into the row array
		imageReader.readNextRow(row);
		displayLine(row);
	}
	
	// turn off all pixels after picture is drawn
	clearPixels();
}

/*	
	Displays one row of an image
	
	@param uint8_t* row: array of RGB values per pixel
*/
void displayLine(uint8_t* row){
	
	int pixelIndex;
	int colorIndex = 0;
	uint32_t color;
	for(pixelIndex=0; pixelIndex<imageReader.width; pixelIndex++){
		color = strip.Color((row[colorIndex+2]), (row[colorIndex+1]), (row[colorIndex]));
		strip.setPixelColor(pixelIndex, color);
		colorIndex += 3;
	}
	strip.show();
	delay(WAITTIME);
}

/*
	prints our the all the files from the given directory
	
	@param File dir: directory to print from
	@param int numTabs: number of tabs to insert for clean printing 
							  of sub directories
							  
	@return numItems: number of files found in the directory
*/
int printDirectory(File dir, int numTabs) {
	int numItems = 0;
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files, rewind for next time
       dir.rewindDirectory();
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       pictures[numItems] = entry.name();
       Serial.print("\t\t: ");
       Serial.println(numItems);
       numItems++;
     }
     entry.close();
   }
   return numItems;
}

/*
	Turns off all of the pixels
*/
void clearPixels(){
	uint32_t black = strip.Color(0,0,0);
	int i;
	for(i=0; i<NUMPIXELS; i++){
		strip.setPixelColor(i, black);
	}
	strip.show();
}


/*
	A test to both load an image and print out the first
	row of RGB values of the image
*/
void printImageRow(){

	// load an image.  For now, pick redbox.bmp by default
	imageReader.loadImage("/bluebox.bmp");
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


