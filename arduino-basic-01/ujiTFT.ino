// Contoh pengujian TFT 2,4"

#include "Adafruit_GFX.h"   
#include "SWTFT.h" 

const int HITAM  = 0x0000;
const int PUTIH  = 0xFFFF;
const int BIRU   = 0x001F;
const int MERAH  = 0xF800;
const int ORANYE = 0xFC08;

SWTFT tft;

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Pengujian TFT LCD");
  
  uint16_t identifier = tft.readID();
  Serial.print("Pengontrol TFT: ");
  Serial.println(identifier, HEX);
  tft.begin(identifier);

  tft.setRotation(1);

  tft.fillScreen(PUTIH); // Warna latarbelakang
  tulisTeks(20, 10, "Tes TFT LCD", 4, HITAM);
}

void loop() 
{
  tulisTeks(0, 65, "123!", 3, BIRU);
  tulisTeks(40, 100, "Hore! OK!", 2, ORANYE);
  tulisTeks(60, 120, "Hore! OK!", 1, MERAH);
  
  delay(1000);
}

// ----------------------------------
// Tulis teks ke posisi (x, y) 
//   dengan ukuran dan warna
// ----------------------------------

void tulisTeks(int x, int y, String teks, 
               int ukuran, int warna) 
{
  tft.setTextColor(warna); 
  tft.setTextSize(ukuran);
  tft.setCursor(x, y);
  tft.println(teks);
}

