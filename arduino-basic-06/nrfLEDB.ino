// Penerimaan data menggunakan NRF24L01
//   yang digunakan untuk mengontrol LED
//   berdasarkan perintah yang diterima

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "RF24_config.h"

const byte PIN_CE = 49;
const byte PIN_CSN = 53;
const uint64_t PIPE = 0xE8E8F0F0E2LL;
const byte PIN_LED = 2;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char perintah[80]; // Penyangga pesan

void setup() 
{
  
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
  Serial.println("Siap menerima data!");
}
 
void loop() 
{
  if (radio.available()) 
  {
    bool selesai = false;  

    strcpy(perintah, "");  
    while (!selesai) 
    {
      selesai = radio.read(perintah, sizeof(perintah));
    }

    Serial.println(perintah);
    if (perintah[0] != 0)
    {    
      // Proses perintah
      if (strcmp(perintah, "LED ON") == 0)
      {
        Serial.println("Siap untuk menghidupkan LED!");
        digitalWrite(PIN_LED, HIGH);  
      }   
      else if (strcmp(perintah, "LED OFF") == 0)
      {
        Serial.println("Siap untuk mematikan LED!");
        digitalWrite(PIN_LED, LOW);  
      }
      else
      {
        Serial.print("Maaf saya tidak mengenal perintah: ");
        Serial.println(perintah);  
      }
    }
  }  
} 

