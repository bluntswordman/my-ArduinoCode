// Contoh untuk membaca isi file ujicoba.txt
//    yang berada di SD card

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
  {
    Serial.println("Problem di SD card!");     
    while (true);
  }
}

void loop()
{
  if (!SD_ok)
    return; // Abaikan perintah-perintah di bawah
    
  // Baca isi file ujicoba.txt
  File fileTes = SD.open("ujicoba.txt", FILE_READ);
  if (fileTes)
  {
    Serial.println("Isi file ujicoba.txt:\n");
  
    while (fileTes.available())
    {
      char kar = fileTes.read();
      Serial.print(kar);
    }

    Serial.println();
    Serial.println("----------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("File ujicoba.txt tidak dapat dibuka!");
  }

  delay(5000); // Tunda untuk pengulangan berikutnya
}

