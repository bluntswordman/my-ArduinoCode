// Contoh pengontrolan IC 74HC595
//   untuk menyajikan kode biner
//   menggunakan SPI

#include <SPI.h>

const byte PIN_LATCH = 53;  // SS
const byte PIN_DATA  = 51;  // MOSI
const byte PIN_CLOCK = 52;  // SCK

void setup() 
{
  Serial.begin(9600);
  
  SPI.begin();                 
  SPI.setBitOrder(MSBFIRST);   
  
  pinMode(PIN_LATCH, OUTPUT);
}

void loop() 
{
  for (byte data = 0; data < 256; data++)        
  {
    Serial.print(data);
    
    digitalWrite(PIN_LATCH, LOW);          
    SPI.transfer(data);                   
    digitalWrite(PIN_LATCH, HIGH);         
    delay(1000);                           
  }
}
