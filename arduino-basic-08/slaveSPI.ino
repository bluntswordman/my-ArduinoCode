// Contoh slave yang digunakan untuk
//   menerima data

#include <SPI.h> 

void setup (void) 
{ 
  Serial.begin (9600); 
  
  pinMode(MISO, OUTPUT); 
  SPCR |= _BV(SPE); // Untuk memilih mode slave
  SPI.attachInterrupt(); // Aktifkan interupsi 

  Serial.println("Siap menerima data...");
} 

// Rutin interupsi SPI
ISR (SPI_STC_vect) 
{  
  // Baca data dari Data Register milik SPI
  byte data = SPDR;  

  // Kirim ke Serial Monitor
  Serial.println(data); 
} 

void loop () 
{ 
 
} 
