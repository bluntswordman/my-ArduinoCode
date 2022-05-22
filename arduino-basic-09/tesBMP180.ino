// Contoh pengujian sensor BMP180

#include <Wire.h>    
#include "Adafruit_BMP085.h"  

Adafruit_BMP085 bmp;  
  
void setup()
{
  Serial.begin(9600); 
  bmp.begin();   
}
 
void loop() 
{
  float suhu = bmp.readTemperature(); 
  float tekananAbsolut = bmp.readPressure(); 
  float tekananRelatif = bmp.readSealevelPressure(); 
  float tinggi = bmp.readAltitude();
 
  Serial.print("Suhu = "); 
  Serial.print(suhu);
  Serial.println(" derajat Celsius");
  Serial.print("Tekanan absolut = ");
  Serial.print(tekananAbsolut);
  Serial.println(" Pa");
  Serial.print("Tekanan relatif (permukaan laut) = ");
  Serial.print(tekananRelatif);
  Serial.println(" Pa");
  Serial.print("Tinggi = ");
  Serial.print(tinggi);
  Serial.println(" meter");
  
  Serial.println();
  
  delay(500); 
}

