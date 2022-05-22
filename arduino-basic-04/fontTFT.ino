// Contoh untuk menentukan jenis font
//    untuk tulisan pada TFT LCD

#include "Adafruit_GFX.h"
#include "SWTFT.h" 

#include "Fonts/FreeMono24pt7b.h"
#include "Fonts/FreeMonoBold24pt7b.h"
#include "Fonts/FreeSerifBoldItalic12pt7b.h"
#include "Fonts/FreeSans12pt7b.h"

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

  tft.setRotation(1);
  tft.fillScreen(PUTIH); // Warna latarbelakang
}

void loop(void) 
{
  tulisDenganFont(0, 40, "Tes 123", 
                  &FreeMono24pt7b, BIRU);
  tulisDenganFont(0, 80, "Tes 123", 
                  &FreeMonoBold24pt7b, BIRU);
  tulisDenganFont(0, 120, "Tes 123", 
                  &FreeSerifBoldItalic12pt7b, MERAH);
  tulisDenganFont(0, 150, "Tes 123", 
                  &FreeSans12pt7b, HITAM);
  
  delay(1000);
}

// ----------------------------------
// Tulis teks ke posisi (x, y) 
//   dengan font dan warna
// ----------------------------------

void tulisDenganFont(int x, int y, String teks, 
                     const GFXfont *font,  
                     int warna) 
{
  tft.setTextColor(warna); 
  tft.setFont(font);
  tft.setCursor(x, y);
  tft.println(teks);
}

