// Contoh bagian penerima
//    yang menggunakan gelombang radio 413MHz
//    untuk membaca perintah dari transmitter

#include "VirtualWire.h"

const byte PIN_LED = 2;
const byte PIN_PENERIMA = 9;

byte wadah[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN; 

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);
  
  vw_set_rx_pin(PIN_PENERIMA);
  vw_setup(2000);  // bit per detik
 
  vw_rx_start();   // Memulai penerimaan data
 
  Serial.begin(9600);
  Serial.println("Siap memantau!");
}

void loop()
{
  if (vw_get_message(wadah, &panjangPesan)) 
  {
    // Peroleh string perintah
    char info[VW_MAX_MESSAGE_LEN + 1];
    int j;
    for (j = 0; j < panjangPesan; j++)
      info[j] = wadah[j];
     
    info[j] = 0; // Pengakhir string
    
    Serial.print(info);
    
    // Reset ke VW_MAX_MESSAGE_LEN
    //    untuk mengatasi bug di pustaka VirtualWire
    panjangPesan = VW_MAX_MESSAGE_LEN;
  }    
}

