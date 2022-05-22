// Contoh untuk membaca data pada EEPROM

#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  byte nilai = EEPROM.read(0);
  Serial.print("Isi pada alamat 0: ");
  Serial.println(nilai);
  
  nilai = EEPROM[1];
  Serial.print("Isi pada alamat 1: ");
  Serial.println(nilai);
}

void loop()
{
  
}

