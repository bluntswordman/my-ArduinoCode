// Contoh untuk menampilkan waktu
//   ke modul TM1637

#include "TM1637.h"
#include "TimeLib.h"

const byte PIN_CLK = 3;    
const byte PIN_DIO = 2;

TM1637 tm1637(PIN_CLK, PIN_DIO);

int8_t dataSegmen[] = {0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  tm1637.set();             // Inisialisasi
  tm1637.clearDisplay();    // Kosongkan penampil
  tm1637.point(POINT_ON);   // Tampilkan pemisah jam
}

void loop() {
  char teks[5];
  sprintf(teks, "%02d%02d", minute(), second());
  
  dataSegmen[0] = teks[0] - '0';
  dataSegmen[1] = teks[1] - '0';
  dataSegmen[2] = teks[2] - '0';
  dataSegmen[3] = teks[3] - '0';
  
  tm1637.display(dataSegmen);
  
  delay(1000);
}

