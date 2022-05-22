// Contoh untuk menampilkan bilangan bulat
//   positif maupun negatif

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
  tampilkanBilBulat(-9876543);  
  delay(2000);

  tampilkanBilBulat(12345678);  
  delay(2000);
}

void tampilkanBilBulat(long bil) 
{
  if (bil <-9999999 || bil > 99999999)
    return;

  lc.clearDisplay(0);

  char teks[9];
  sprintf(teks, "%ld", bil);

  for (int pos = 0; pos < strlen(teks); pos++) 
    lc.setChar(0, 7 - pos, teks[pos], false);
}

