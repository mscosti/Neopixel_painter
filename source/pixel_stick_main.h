//-------------------------------------------------------------------
#ifndef __pixel_stick_main_H__
#define __pixel_stick_main_H__
//-------------------------------------------------------------------
 
#include <arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SdInfo.h>
#include <SdFatUtil.h>
#include <SdFatmainpage.h>
#include <SdFat.h>
#include <Sd2PinMap.h>
#include <Sd2Card.h>
#include <FatStructs.h>
#include <SD.h>
#include <SdInfo.h>
#include <SdFatUtil.h>
#include <SdFatmainpage.h>
#include <SdFat.h>
#include <Sd2PinMap.h>
#include <Sd2Card.h>
#include <FatStructs.h>
#include <SD.h>
 
//-------------------------------------------------------------------
 
//-------------------------------------------------------------------
 
// Put yout declarations here
 
//-------------------------------------------------------------------
 
//===================================================================
// -> DO NOT WRITE ANYTHING BETWEEN HERE...
// 		This section is reserved for automated code generation
// 		This process tries to detect all user-created
// 		functions in main_sketch.cpp, and inject their
// 		declarations into this file.
// 		If you do not want to use this automated process,
//		simply delete the lines below, with "&MM_DECLA" text
//===================================================================
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_BEG@---------------------
void testParseString();
void imageToRows(uint8_t* imageArray, uint8_t* rowArray);
void parseString (char* toParse, char* toArray);
void printImageRow();
void serialEvent();
void createDummyRow(int* row);
void clearPixels();
int printDirectory(File dir, int numTabs);
void displayLine(uint8_t* row);
void displayPic(char* imgFile);
void displayMenu();
void loop();
void setup();
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_END@---------------------
// -> ...AND HERE. This space is reserved for automated code generation!
//===================================================================
 
 
//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
 
 
 
