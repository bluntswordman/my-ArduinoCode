// Contoh untuk membaca data float dan
//   string pada EEPROM

#include <EEPROM.h>

void setup()
{
  float bil;
  char teks[12];
  
  Serial.begin(9600);

  EEPROM.get(0, bil);
  Serial.print("Data bilangan: ");
  Serial.println(bil);

  EEPROM.get(4, teks);
  Serial.print("Data teks: ");
  Serial.println(teks);
}

void loop()
{
  
}

