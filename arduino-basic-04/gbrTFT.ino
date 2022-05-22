// Contoh pembuatan gambar pada TFT LCD

#include "Adafruit_GFX.h"
#include "SWTFT.h" 

const int HITAM  = 0x0000;
const int PUTIH  = 0xFFFF;
const int BIRU   = 0x001F;
const int MERAH  = 0xF800;

SWTFT tft;

void setup(void) 
{
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  
  tft.setRotation(1);    // Arah memanjang
  tft.fillScreen(PUTIH); // Warna latarbelakang
}

void loop(void) 
{
  // Buat segitiga
  tft.fillTriangle(40, 73, 60, 45, 60, 73, BIRU);
  tft.fillRoundRect(63, 45, 37, 29, 0, BIRU);
  tft.fillRoundRect(30, 75, 80, 30, 5, MERAH);
  
  // Buat roda
  tft.fillCircle(50, 100, 10, HITAM);
  tft.fillCircle(90, 100, 10, HITAM);

  // Buat garis untuk jalan
  tft.drawLine(10, 110, 200, 110, BIRU);
  
  delay(1000);
}

