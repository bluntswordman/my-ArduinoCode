// Contoh pengujian untuk membaca data 
//   pada EEPROM AT24C256

#include <Wire.h>
#include "AT24CX.h"

AT24CX memori; // Objek EEPROM

void setup() 
{
  Serial.begin(9600);  

  float bil;
  char teks[12];
  
  bil = memori.readFloat(0);
  memori.readChars(4, teks, sizeof(teks));
  
  Serial.print("Data bilangan: ");
  Serial.println(bil);

  Serial.print("Data teks: ");
  Serial.println(teks);
}

void loop() 
{
  

}
