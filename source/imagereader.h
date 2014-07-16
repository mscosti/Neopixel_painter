//-------------------------------------------------------------------
#ifndef __imagereader_H__
#define __imagereader_H__
//-------------------------------------------------------------------

#include <arduino.h>
#include <SD.h>
//-------------------------------------------------------------------

//-------------------------------------------------------------------

class ImageReader {
	public:
		// width and height of the image
		int width, height;
		
		// the step size of a row in bytes
		int rowStep;
		
		// All the metadata
		uint8_t info[54];
		
		// The bitmap file itself that will be read
		File bitmap;
		
		// class function definitions
		ImageReader();
		void loadImage(char*);
		void readNextRow (uint8_t*);
};

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
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_END@---------------------
// -> ...AND HERE. This space is reserved for automated code generation!
//===================================================================


//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
