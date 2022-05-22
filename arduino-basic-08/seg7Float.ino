// Contoh untuk menampilkan bilangan pecahan

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
  float bil = -978.5671;
  tampilkanBilReal(bil, 3);  
  delay(2000);

  bil = 13465.4567;
  tampilkanBilReal(bil, 1);  
  delay(2000);
}

void tampilkanBilReal(float bil, byte n) 
{
  lc.clearDisplay(0);

  long bilBaru = bil * pow(10.0, n); 
  
  char teks[9];
  sprintf(teks, "%ld", bilBaru);
  int posTitik = 8 - strlen(teks) + n;
  
  for (int pos = 0; pos < strlen(teks); pos++)  {
    if (pos == 8)
      break;

    int lokasi = 7 - pos;
    boolean adaTitik = (lokasi == posTitik);
    lc.setChar(0, 7 - pos, teks[pos], adaTitik);
  }
}

