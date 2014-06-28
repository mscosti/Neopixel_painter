/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "pixel_stick_main.h"

void setup() {                
  pinMode(13, OUTPUT);     
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);           
  digitalWrite(13, LOW); 
  delay(500);           
}
