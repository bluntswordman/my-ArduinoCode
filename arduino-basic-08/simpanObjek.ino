// Contoh untuk menulis data float dan string

#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  float bil = 3.14;
  EEPROM.put(0, bil);
  delay(4);

  char teks[12];
  strcpy(teks, "Alpha Bravo");
  EEPROM.put(4, teks);
  delay(4);
  
  Serial.println("Data float dan string");
  Serial.println("sudah disimpan");
}

void loop()
{
  
}

