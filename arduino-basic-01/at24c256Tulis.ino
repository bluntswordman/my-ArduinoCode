// Contoh pengujian untuk menulis data 
//   pada EEPROM AT24C256

#include <Wire.h>
#include "AT24CX.h"

AT24CX memori; // Objek EEPROM

void setup() 
{
  Serial.begin(9600);  

  float bil = 7.1567;
  memori.writeFloat(0, bil);
  
  char teks[12];
  strcpy(teks, "Romeo");
  memori.writeChars(4, teks, sizeof(teks));
  
  Serial.println("Data float dan string");
  Serial.println("sudah disimpan");
}

void loop() 
{
  

}
