// Pengiriman data menggunakan NRF24L01

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "RF24_config.h"

const byte PIN_CE = 9;
const byte PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

// Objek NRF24L01
RF24 radio(PIN_CE, PIN_CSN);

char pesan[80]; // penyangga pesan
int pencacah = 1;

void setup() 
{
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(PIPE);
}
 
void loop() 
{
  kirimPerintah("LED ON");
  delay(1000);

  kirimPerintah("MOTOR ON");
  delay(1000);
  
  kirimPerintah("LED OFF");
  delay(1000);
}

void kirimPerintah(String st)
{
  strcpy(pesan, st.c_str()); 
  Serial.print(pesan);
    
  bool ok = radio.write(pesan, strlen(pesan)); 
  if (ok)
    Serial.println(" OK...");
  else
    Serial.println(" Gagal...");  

  pencacah++; // Naikkan pencacah
        
  radio.powerDown();  
  delay(1000);
  radio.powerUp();    
}

