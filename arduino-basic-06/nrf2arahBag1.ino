// -----------------------------------------------
// Contoh komunikasi dua arah
//   menggunakan nRF24L01
//   Versi pengirim perintah
// -----------------------------------------------

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const byte PIN_CE = 9;
const byte PIN_CSN = 10;
const uint64_t PIPA_1 = 0xE8E8F0F0E2LL;
const uint64_t PIPA_2 = 0xE8E8F0F0ABLL;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[80]; // Penyangga pesan

void setup() 
{
  Serial.begin(9600);
  
  radio.begin();
  radio.setRetries(15, 15);
  
  radio.openWritingPipe(PIPA_1);
  radio.openReadingPipe(1, PIPA_2);
  radio.startListening();

  Serial.println("Silakan untuk mengirim perintah...");
}
 
void loop() 
{
  // Baca perintah dari port serial
  if (Serial.available()) 
  {
    // Baca perintah
    String perintah = Serial.readString();
    
    strcpy(pesan, perintah.c_str());

    radio.stopListening();
    bool ok = radio.write(pesan, strlen(pesan));
    radio.startListening();

    if (ok) 
    {
      Serial.print("Perintah ");
      Serial.print(pesan);
      Serial.println(" berhasil dikirim");
    }
    else 
    {
      Serial.print("Perintah ");
      Serial.print(pesan);
      Serial.println(" gagal dikirim");
    }
  }

  // Baca kiriman dengan menunggu maksimum 250 milidetik
  bool waktuHabis = false;
  unsigned long waktuAwal = millis();
  while (!radio.available() && !waktuHabis) 
  {
    if (millis() - waktuAwal > 250)
      waktuHabis = true;
  }

  if (!waktuHabis) 
  {
    radio.read(pesan, sizeof(pesan));
    Serial.print("Jawaban: ");
    Serial.println(pesan);
  }
}

