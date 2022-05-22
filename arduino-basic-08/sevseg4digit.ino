// Contoh penggunaan pustaka SevSeg
//   pada modul tujuh segmen 4 digit

#include "SevSeg.h"

SevSeg sevseg; 

void setup() 
{
  byte jumDigit = 4;
  byte pinDigit[] = {2, 3, 4, 5};
  byte pinSegment[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_ANODE, jumDigit, pinDigit, pinSegment);
}

void loop() 
{
  sevseg.setNumber(1276, 3);
  sevseg.refreshDisplay(); 
}
