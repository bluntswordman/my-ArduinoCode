// Pengujian Modul MAX7219

#include "LedControl.h" 

const int JUMLAH_LED = 1;
const byte PIN_CS  = 10;
const byte PIN_CLK = 11;
const byte PIN_DIN = 12;

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, JUMLAH_LED); 
 
void setup()
{
  // Menghidupkan penampil nomor 0
  lc.shutdown(0, false);
  
  // Mengatur intensitas kecerahan (0 hingga 15)
  lc.setIntensity(0,8);
  
  // Menghapus layar
  lc.clearDisplay(0);
}
void loop()
{
  for (int baris = 0; baris < 8; baris++)
  {
    for (int kolom = 0; kolom < 8; kolom++)
    {
      // Menampilkan LED pada kolom dan baris
      lc.setLed(0, baris, kolom, true); 
      delay(100);
    }
  }
 
  delay(1000);
   
  for (int baris = 0; baris < 8; baris++)
  {
    for (int kolom = 0; kolom < 8; kolom++)
    {
      // Mematikan LED pada kolom dan baris
      lc.setLed(0, baris, kolom, false); 
      delay(100);
    }
  }
}

