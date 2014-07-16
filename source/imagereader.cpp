/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "imagereader.h"

// empty constructor
// for now it doesn't have to do anything
ImageReader::ImageReader(){ }

void ImageReader::loadImage (char* filename) {
	bitmap = SD.open(filename);

	// read in all the metadata
	for (int i = 0; i < 54; i++){
		info[i] = bitmap.read();
	}

	// width and height are 4 bytes at 
	// offset 18 and 22 respectively
	width = info[18];
	height = info[22];
	
	// rowstep = bytes per channel * pixel width
	// image is in RGB, so 3 channels at 1 byte per channel
	rowStep = width*3;
}

// read an entire row into the passed row array
void ImageReader::readNextRow (uint8_t* row) {

	for (int i = 0; i < rowStep; i++){
		uint8_t val = bitmap.read();
		row[i] = val;
	}
}

