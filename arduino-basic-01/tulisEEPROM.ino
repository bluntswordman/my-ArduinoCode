// Contoh untuk menulis data ke EEPROM

#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  EEPROM.write(0, 5);
  delay(4);
  
  EEPROM[1] = 6;
  delay(4);
  
  Serial.println("Data sudah disimpan");
  Serial.println("pada alamat 0 dan 1");
}

void loop()
{
  
}

