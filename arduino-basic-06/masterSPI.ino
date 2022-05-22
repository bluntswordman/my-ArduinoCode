// Contoh untuk mengirimkan data ke
//   Arduino Uno melalui SPI

#include <SPI.h> 

void setup (void) 
{  
  digitalWrite(SS, HIGH); 
  SPI.begin(); 
} 

void loop (void) 
{ 
  for (byte data = 0; data < 256; data++) 
  {
    digitalWrite(SS, LOW); 
    SPI.transfer (data); 
    digitalWrite(SS, HIGH); 
    delay(1000);
  } 
} 
