// Contoh pengiriman informasi dari transmitter
//    yang menggunakan gelombang radio 315MHz

#include "VirtualWire.h"

const byte PIN_PENGIRIM = 10;

int pencacah = 1;

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
  char teks[30] = "";
  
  sprintf(teks, "Pengiriman ke-%d\n", pencacah);
  Serial.print(teks);
  
  vw_send((uint8_t *) teks, strlen(teks));
  vw_wait_tx();

  pencacah++; // Naikkan pencacah sebesar 1
  delay(3000);
}

