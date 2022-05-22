// Contoh untuk mengakses modul GPS
//   menggunakan pustaka TinyGPS

#include "TinyGPS.h"

TinyGPS gps;

void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() 
{ 
  if (Serial2.available()) 
  { 
    char karakter = Serial2.read();
 
    if (gps.encode(karakter)) {
      float lintang, bujur;

      gps.f_get_position(&lintang, &bujur);
      
      Serial.print("Posisi lintang: ");
      Serial.println(lintang, 7);

      Serial.print("Posisi Bujur  : ");
      Serial.println(bujur, 7);   

      Serial.println();
    }
  }
}

