// Contoh pemakaian modul penampil tujuh segmen
//   8 digit menggunakan MAX7219

#include "LedControl.h"

const byte PIN_DIN = 2;
const byte PIN_CLK = 3;
const byte PIN_CS = 4;

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, 1);

void setup() 
{
  lc.shutdown(0,false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() 
{ 
  // Tulis a
  lc.setChar(0, 7, 'a', false);

  // Tulis r
  lc.setRow(0, 6, 0x05);

  // Tulis d
  lc.setChar(0, 5, 'd', false);

  // Tulis u
  lc.setRow(0, 4, 0x1C);

  // Tulis i
  lc.setRow(0, 3, 0x10);

  // Tulis n
  lc.setRow(0, 2, 0x15);

  // Tulis o
  lc.setRow(0, 1, 0x1D);

  delay(2000);
}

