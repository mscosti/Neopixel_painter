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
void theaterChaseRainbow(uint8_t wait);
void theaterChase(uint32_t c, uint8_t wait);
void rainbowCycle(uint8_t wait);
void rainbow(uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
void displayLine(int* row);
void clearPixels();
void testParseString();
void imageToRows(int* imageArray, int* rowArray);
void parseString (char* toParse, int* toArray);
void createDummyRow(int* row);
void loop();
void setup();
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_END@---------------------
// -> ...AND HERE. This space is reserved for automated code generation!
//===================================================================
 
 
//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
 
 
