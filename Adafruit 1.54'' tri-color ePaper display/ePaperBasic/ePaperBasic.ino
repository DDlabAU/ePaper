//Include the two necessary libraries
#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"

#define EPD_CS     10
#define EPD_DC      9
#define SRAM_CS     8
#define EPD_RESET   5 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    3 // can set to -1 to not use a pin (will wait a fixed delay)

Adafruit_IL0373 epd(152, 152 ,EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);


void setup() {
  //connect to display
  epd.begin();

  //make sure the buffer is empty before start
  epd.clearBuffer();

  //clear the screen for any existing graphics
  epd.fillScreen(EPD_WHITE);

  // YOUR CODE - add your graphics to the buffer

   
  //display graphics on display
  epd.display();
}

void loop() {
  //don't do anything!

}
