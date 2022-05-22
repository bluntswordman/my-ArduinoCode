// Contoh untuk menguji pengukuran jarak objek
//   menggunakan HC-SR04 atau US-015

#include "NewPing.h"

const byte PIN_TRIG = 5;
const byte PIN_ECHO = 4;

NewPing sensorUltra(PIN_TRIG, PIN_ECHO, 300);

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  // Hitung jarak
  int jarak = sensorUltra.ping_cm();   

  // Tampilkan ke Serial Monitor
  Serial.print(jarak); 
  Serial.println(" cm");
  
  delay(500);
}

