// Contoh untuk menguji SD card

#include <SD.h>

const byte PIN_CS = 53;
boolean SD_ok;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_CS, OUTPUT);
  
  SD_ok = SD.begin(PIN_CS);
  if (SD_ok)
    Serial.println("SD card OK!");   
  else
    Serial.println("Problem di SD card!");     
}

void loop()
{
    
}

