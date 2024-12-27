#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

// Include the header files that contain the icons
#include "TDI-Boost-Images.h"

int frm = 0; 
int frm_int = 1; 

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);	// landscape

  tft.fillScreen(TFT_BLACK);

  // Swap the colour byte order when rendering
  tft.setSwapBytes(true);
}

void loop()
{
  frm = frm + frm_int; 
  if ((frm > 60) && (frm_int > 0)) {
    frm = 60; 
    frm_int = -1;
  } else if ((frm < 0) && (frm_int < 0)) {
    frm = 0; 
    frm_int = 1; 
  }

  // Draw the boost frame 
  tft.pushImage(0, 0, 240, 240, epd_bitmap_allArray[frm]);
}
