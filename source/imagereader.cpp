/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "imagereader.h"
//#include <string>
//
//using namespace std;

class ImageReader {
    int width, height, currentRow;
  public:
    ImageReader (String);
    int* readNextRow ();
};

ImageReader::ImageReader (String filename) {
  currentRow=0;
  height = 60;
  width = 60;
}

int* ImageReader::readNextRow () {

	//todo
}
