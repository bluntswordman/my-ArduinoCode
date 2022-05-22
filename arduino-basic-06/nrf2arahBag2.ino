// Penerimaan perintah menggunakan NRF24L01
//    untuk mengontrol LED

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const byte PIN_CE = 49;
const byte PIN_CSN = 53;
const uint64_t PIPE_1 = 0xE8E8F0F0E2LL;
const uint64_t PIPE_2 = 0xE8E8F0F0ABLL;
const byte PIN_LED = 2;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[80]; // Penyangga pesan

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  
  radio.begin();
  radio.setRetries(15, 15);
  
  radio.openReadingPipe(1, PIPE_1);
  radio.openWritingPipe(PIPE_2);
  radio.startListening();
  
  Serial.println("Siap menerima perintah!");
}
 
void loop() 
{
  if (radio.available()) 
  {
    radio.read(pesan, sizeof(pesan));
    Serial.println(pesan);
    
    if (strcmp(pesan, "LED ON") == 0) 
    {
      digitalWrite(PIN_LED, HIGH);
      
      strcpy(pesan, "LED telah dihidupkan");
      
      radio.stopListening();
      bool ok = radio.write(pesan, strlen(pesan));
      radio.startListening();
      if (ok) 
      {
        Serial.print("Informasi LED dihidupkan");
        Serial.println(" telah diterima pengirim");
      }  
      else 
      {
        Serial.print("Informasi LED dihidupkan");
        Serial.println(" gagal diterima pengirim");
      }
    }  
    else
      if (strcmp(pesan, "LED OFF") == 0) 
      {
        digitalWrite(PIN_LED, LOW);  
        
        strcpy(pesan, "LED telah dimatikan");

        radio.stopListening();  
        bool ok = radio.write(pesan, strlen(pesan));
        radio.startListening();
      
        if (ok) 
        {
          Serial.print("Informasi LED dimatikan");
          Serial.println(" telah diterima pengirim");
        }  
        else 
        {
          Serial.print("Informasi LED dimatikan");
          Serial.println(" gagal diterima pengirim");
        }
      }
      else 
      {
        Serial.println("Perintah tidak dikenal!");
        strcpy(pesan, "Perintah tidak dikenal!");

        radio.stopListening();
        radio.write(pesan, strlen(pesan));
        radio.startListening();
      }
  }  
}

