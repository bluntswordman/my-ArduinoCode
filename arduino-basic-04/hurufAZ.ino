// Contoh untuk menampilkan huruf A hingga Z

#include "LedControl.h" 

const int JUMLAH_LED = 1;
const byte PIN_CS  = 10;
const byte PIN_CLK = 11;
const byte PIN_DIN = 12;

const byte HURUF[] = 
{
  0x3C, 0x24, 0x24, 0x7E, 0x62, 0x62, 0x62, 0x00, // A
  0x7C, 0x24, 0x24, 0x3E, 0x32, 0x32, 0x7E, 0x00, // B
  0x3E, 0x22, 0x20, 0x60, 0x60, 0x62, 0x7E, 0x00, // C
  0x7E, 0x22, 0x22, 0x32, 0x32, 0x32, 0x7E, 0x00, // D
  0x3E, 0x20, 0x20, 0x78, 0x60, 0x60, 0x7E, 0x00, // E
  0x3E, 0x20, 0x20, 0x78, 0x60, 0x60, 0x60, 0x00, // F
  0x3E, 0x22, 0x20, 0x6E, 0x62, 0x62, 0x7E, 0x00, // G
  0x24, 0x24, 0x24, 0x7E, 0x62, 0x62, 0x62, 0x00, // H
  0x3E, 0x08, 0x08, 0x18, 0x18, 0x18, 0x3E, 0x00, // I
  0x1C, 0x08, 0x08, 0x0C, 0x0C, 0x4C, 0x7C, 0x00, // J
  0x24, 0x24, 0x28, 0x70, 0x68, 0x68, 0x66, 0x00, // K
  0x20, 0x20, 0x20, 0x60, 0x60, 0x62, 0x7E, 0x00, // L
  0x36, 0x3E, 0x2A, 0x62, 0x62, 0x62, 0x62, 0x00, // M
  0x32, 0x2A, 0x2A, 0x6A, 0x6A, 0x66, 0x62, 0x00, // N
  0x3E, 0x22, 0x22, 0x62, 0x62, 0x62, 0x7E, 0x00, // O
  0x3E, 0x22, 0x22, 0x7E, 0x60, 0x60, 0x60, 0x00, // P
  0x3E, 0x22, 0x22, 0x62, 0x6A, 0x64, 0x7A, 0x00, // Q
  0x3E, 0x22, 0x22, 0x7E, 0x68, 0x68, 0x66, 0x00, // R
  0x3C, 0x24, 0x20, 0x3E, 0x0E, 0x6E, 0x7E, 0x00, // S
  0x3E, 0x08, 0x08, 0x18, 0x18, 0x18, 0x18, 0x00, // T
  0x22, 0x22, 0x22, 0x62, 0x62, 0x62, 0x7E, 0x00, // U
  0x22, 0x22, 0x22, 0x64, 0x68, 0x70, 0x60, 0x00, // V
  0x22, 0x22, 0x22, 0x6A, 0x6A, 0x7E, 0x7E, 0x00, // W
  0x24, 0x24, 0x3C, 0x18, 0x7E, 0x62, 0x62, 0x00, // X
  0x22, 0x22, 0x22, 0x3E, 0x18, 0x18, 0x18, 0x00, // Y
  0x7E, 0x42, 0x1E, 0x60, 0x60, 0x62, 0x7E, 0x00, // Z
};

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
  for (char karakter = 'A'; karakter <= 'Z'; karakter++) 
  {
    int posisi = (karakter - 'A') * 8;    
    
    // Tampilkan
    for (int baris = 0; baris < 8; baris++)
    {
        byte nilai = HURUF[baris + posisi];
        for (int bit = 7; bit >= 0; bit--)
        {
           byte kolom = 7 - bit;
           if (bitRead(nilai, bit) == 1)
             lc.setLed(0, baris, kolom, true); 
           else
             lc.setLed(0, baris, kolom, false); 
        } 
    } 
    
    delay(2000);
  } 
}

