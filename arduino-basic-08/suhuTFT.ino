// Contoh untuk menampilkan informasi
//    suhu dan kelembaban udara
//    pada TFT LCD

#include "Adafruit_GFX.h"
#include "SWTFT.h" 
#include "dht.h"

#include "Fonts/FreeMonoBold24pt7b.h"
#include "Fonts/FreeSerifBoldItalic12pt7b.h"

const int HITAM  = 0x0000;
const int PUTIH  = 0xFFFF;
const int BIRU   = 0x001F;
const int MERAH  = 0xF800;
const int PIN_DHT11 = 10;

dht sensorDHT;

SWTFT tft;

void setup(void) 
{
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  
  tft.setRotation(1);    // Arah memanjang
  tft.fillScreen(PUTIH); // Warna latarbelakang

  tulisDenganFont(20, 40, "SUHU", 
                  &FreeSerifBoldItalic12pt7b, MERAH);

  tulisDenganFont(20, 120, "KELEMBABAN", 
                  &FreeSerifBoldItalic12pt7b, MERAH);
}

void loop(void) 
{
  // Peroleh data darui sensor 
  sensorDHT.read11(PIN_DHT11);
  float kelembapan = sensorDHT.humidity;
  float suhu = sensorDHT.temperature;

  // Tampilkan data suhu ke TFT LCD
  char teks[7];
  dtostrf(suhu, 0, 2, teks);
  
  tft.fillRect(20, 50, 200, 40, PUTIH);
  tulisDenganFont(20, 80, teks, 
                  &FreeMonoBold24pt7b, BIRU);
                  
  tulisDenganFont(162, 72, "o", 
                  &FreeMonoBold24pt7b, BIRU);

  tulisDenganFont(192, 80, "C", 
                  &FreeMonoBold24pt7b, BIRU);

  // Tampilkan data kelembapan ke TFT LCD
  dtostrf(kelembapan, 0, 2, teks);
  strcat(teks, "%");
  
  tft.fillRect(20, 130, 200, 40, PUTIH);
  tulisDenganFont(20, 160, teks, 
                  &FreeMonoBold24pt7b, BIRU);
  
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

