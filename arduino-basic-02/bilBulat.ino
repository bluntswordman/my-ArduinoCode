// Contoh penggunaan TM1637

#include "TM1637.h"

const byte PIN_CLK = 3;    
const byte PIN_DIO = 2;

TM1637 tm1637(PIN_CLK, PIN_DIO);

void setup() 
{
  Serial.begin(9600);
  tm1637.set();             // Inisialisasi
  tm1637.clearDisplay();    // Kosongkan penampil
}

void loop() 
{
  // Bangkitkan bilangan acak antara 0 dan 9999
  int bilangan = random(10000);

  tampilBilangan(bilangan);
  delay(2000);
}

void tampilBilangan(unsigned int bil) 
{
  int8_t dataSegmen[] = {0, 0, 0, 0};
  
  char teks[5];
  sprintf(teks, "%d", bil);

  // Kosongkan tampilan
  dataSegmen[0] = 0x7f;
  dataSegmen[1] = 0x7f;
  dataSegmen[2] = 0x7f;
  dataSegmen[3] = 0x7f;

  // Tulis angka sesuai jumlah digit di teks
  for (int j = 0; j < strlen(teks); j++) 
    dataSegmen[j] = teks[j] - '0'; 

  tm1637.display(dataSegmen);
}

