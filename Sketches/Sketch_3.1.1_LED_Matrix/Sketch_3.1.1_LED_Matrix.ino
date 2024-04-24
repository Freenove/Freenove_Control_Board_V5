/*
  Sketch 3.1.1
  LED dot matrix display

  modified 2024/4/18
  by http://www.freenove.com
*/
#include "Arduino_LED_Matrix.h"  // Include the LED_Matrix library

ArduinoLEDMatrix matrix;  // Create an instance of the ArduinoLEDMatrix class

void setup() {
  matrix.begin();  // Initialize the LED matrix
}

const uint32_t fullOn[] = {
  0xffffffff,
  0xffffffff,
  0xffffffff
};
const uint32_t fullOff[] = {
  0x00000000,
  0x00000000,
  0x00000000
};
void loop() {
  matrix.loadFrame(fullOff);
  delay(250);
  matrix.loadFrame(fullOn);
  delay(250);
}
