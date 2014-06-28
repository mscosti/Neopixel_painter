/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "imagereader.h"
#include <SD.h>
//#include <string>
//
//using namespace std;

class ImageReader {
    int width, height;
    unsigned char info[54];
    File bitmap;
  public:
    ImageReader (char*);
    int* readNextRow ();
};

ImageReader::ImageReader (char* filename) {
  bitmap = SD.open(filename);
  
  int i = 0;
  for (i; i < 54; i++){
	info[i] = bitmap.read();
  }
  
  width = *(int*)&info[18];
  height = *(int*)&info[22];
}

int* ImageReader::readNextRow () {
	int size = 3 * width;
	int i = 0;
	
	int row[size];
	
	for (i; i < size; i++){
		unsigned char val = bitmap.read();
		row[i] = (int)val;
	}
	
	return row;
}

