// Contoh bagian penerima
//    yang menggunakan gelombang radio 413MHz
//    untuk membaca perintah dari transmitter
//    guna mematikan/menghidupkan LED

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
  Serial.println("Siap menerima perintah!");
}

void loop()
{
  if (vw_get_message(wadah, &panjangPesan)) 
  {
    // Peroleh string perintah
    char perintah[VW_MAX_MESSAGE_LEN + 1];
    int j;
    for (j = 0; j < panjangPesan; j++)
      perintah[j] = wadah[j];
    
    perintah[j] = 0; // Pengakhir string
  
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
    
    // Reset ke VW_MAX_MESSAGE_LEN
    //    untuk mengatasi bug di pustaka VirtualWire
    panjangPesan = VW_MAX_MESSAGE_LEN;
  }    
}


