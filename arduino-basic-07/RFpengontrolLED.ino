// Contoh pengiriman perintah dari bagian pengirim
//    yang menggunakan gelombang radio 315MHz
//    untuk menghidupkan/mematikan LED
//    yang terletak pada bagian penerima

#include "VirtualWire.h"

const byte PIN_PENGIRIM = 10;

void setup()
{
  // Inisialisasi Pengirim
  vw_set_tx_pin(PIN_PENGIRIM);
  vw_setup(2000); // Kecepatan 2000 bit per detik
  
  // Inisialisasi port serial
  Serial.begin(9600);
}

void loop()
{
  // Kirim perintah
  kirimPerintah("LED ON");  
  delay(3000);
  
  kirimPerintah("MOTOR ON");  
  delay(3000);
  
  kirimPerintah("LED OFF");  
  delay(3000);
}

// -------------------------------
// Fungsi untuk mengirim perintah
//   dengan asumsi perintah
//   tidak panjang (< 25 karakter)
// -------------------------------
void kirimPerintah(char *perintah)
{
  Serial.println(perintah);
  vw_send((uint8_t *) perintah, strlen(perintah));
  vw_wait_tx();
  
  delay(1000);
}

