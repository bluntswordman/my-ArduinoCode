// Contoh penggunaan pustaka SevSeg
//   pada modul tujuh segmen 4 digit
//   untuk menampilkan suhu

#include "SevSeg.h"

const int SELANG = 1000;

SevSeg sevseg; 

unsigned long waktuAwal = millis();
int suhu;
  
void setup() 
{
  byte jumDigit = 4;
  byte pinDigit[] = {2, 3, 4, 5};
  byte pinSegment[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_CATHODE, jumDigit, pinDigit, pinSegment);
}

void loop() 
{
  if (abs(millis() - waktuAwal) > SELANG)
  {
    float celsius = analogRead(A0) * 0.48876;
    suhu = celsius * 100;
    waktuAwal = millis();
  }
  
  sevseg.setNumber(suhu, 2);
  sevseg.refreshDisplay();
}
