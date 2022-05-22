// Contoh bagian penerima
//    yang menggunakan gelombang radio 413MHz
//    untuk membaca perintah dari transmitter
//    guna mematikan/menghidupkan LED dan kipas

#include "VirtualWire.h"

const byte PIN_LED1 = 2;
const byte PIN_LED2 = 3;

const byte PIN_PENERIMA = 9;
const byte PIN_PENGIRIM = 10;

byte wadah[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN; 

void setup()
{
  // Atur pin
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  
  // Atur pengirim dan penerima
  vw_set_tx_pin(PIN_PENGIRIM);
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

    Serial.print("Perintah: ");
    Serial.println(perintah);
    
    // Proses perintah
    if (strcmp(perintah, "LED1 ON") == 0)
    {
      Serial.println("Siap untuk menghidupkan LED pertama!");
      digitalWrite(PIN_LED1, HIGH);  
    }   
    else if (strcmp(perintah, "LED1 OFF") == 0)
    {
      Serial.println("Siap untuk mematikan LED!");
      digitalWrite(PIN_LED1, LOW);  
    }
    else if (strcmp(perintah, "LED2 ON") == 0)
    {
      Serial.println("Siap untuk menghidupkan LED kedua!");
      digitalWrite(PIN_LED2, HIGH);  
    }
    else if (strcmp(perintah, "LED2 OFF") == 0)
    {
      Serial.println("Siap untuk mematikan LED kedua!");
      digitalWrite(PIN_LED2, LOW);  
    }
    
    // Beritahu ke pengirim mengenai perintah yang didapat
    kirimTanggapan(perintah);
    
    // Reset ke VW_MAX_MESSAGE_LEN
    //    untuk mengatasi bug di pustaka VirtualWire
    panjangPesan = VW_MAX_MESSAGE_LEN;
  }    
}

void kirimTanggapan(char *teks)
{
  vw_send((uint8_t *) teks, strlen(teks));  
  vw_wait_tx();
  
  delay(500);
}

