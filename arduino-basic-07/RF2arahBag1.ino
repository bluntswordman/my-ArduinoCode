// Komunikasi dua arah
//    yang menggunakan gelombang radio 413MHz
//    Versi bagian pengirim
// -------------------------------------------

#include "VirtualWire.h"

const byte PIN_PENGIRIM = 10;
const byte PIN_PENERIMA = 9;

byte wadah[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN; 

void setup()
{
  // Inisialisasi Pengirim
  vw_set_tx_pin(PIN_PENGIRIM);
  vw_set_rx_pin(PIN_PENERIMA);
  
  vw_setup(2000); // Kecepatan 2000 bit per detik
  vw_rx_start();   // Memulai penerimaan data
 
  // Inisialisasi port serial
  Serial.begin(9600);
}

void loop()
{
  kirimPerintah("LED1 ON");
  delay(3000);
  
  kirimPerintah("LED2 ON");
  delay(3000);
  
  kirimPerintah("LED2 OFF");
  delay(3000);
  
  kirimPerintah("LED1 OFF");
  delay(3000);
}

// ---------------------------------------
// Fungsi untuk mengirim perintah
//   dan memeriksa tanggapan dari penerima
//   Perintah akan diulang sekiranya
//   perintah dan tanggapan tidak sama
// ---------------------------------------
void kirimPerintah(char *perintah)
{
  int j;
  bool ok = false;
  char pesan[VW_MAX_MESSAGE_LEN + 1];
  
  do
  {
     // Kirim pesan
     Serial.print("Perintah: ");
     Serial.println(perintah);
     vw_send((uint8_t *) perintah, strlen(perintah));
     vw_wait_tx();
  
     delay(2000);

     // Ambil perintah
     if (vw_get_message(wadah, &panjangPesan)) 
     {
       for (j = 0; j < panjangPesan; j++)
         pesan[j] = wadah[j];
         
       pesan[j] = 0; // Pengakhir string
       Serial.print("Tanggapan: ");
       Serial.println(pesan);
       
       // Reset ke VW_MAX_MESSAGE_LEN
       //    untuk mengatasi bug di pustaka VirtualWire
       panjangPesan = VW_MAX_MESSAGE_LEN;
     }
     
     // Cek perintah
     if (strcmp(perintah, pesan) == 0)
       ok = true; 
     else
       delay(500);  
  }  while (not ok); 
}

