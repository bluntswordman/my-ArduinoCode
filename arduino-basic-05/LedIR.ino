// Pengontrolan LED
//   menggunakan IR remote control buatan Keyes

#include "IRremote.h"

const byte PIN_IR = 2; 
const byte PIN_LED = 4;
const long NILAI_ON = 0xFF42BD;  // LED hidup
const long NILAI_OFF = 0xFF52AD; // LED padam

IRrecv penerima(PIN_IR);
decode_results hasil;
  
void setup() 
{
  pinMode(PIN_LED, OUTPUT);
  
  penerima.enableIRIn();
}

void loop()
{
  if (penerima.decode(&hasil)) 
  {
    // Proses untuk mengontrol LED
    if (hasil.value == NILAI_ON)
      digitalWrite(PIN_LED, HIGH);
    else
      if (hasil.value == NILAI_OFF)
        digitalWrite(PIN_LED, LOW);
      
    // Peroleh nilai berikutnya
    penerima.resume();   
  }
}

