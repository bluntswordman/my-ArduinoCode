// Contoh penyajian informasi suhu
//   pada OLED

#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g; 

char strSuhu[10]; // String berisi data suhu

void setup() 
{
}

void loop() 
{
  float celsius = analogRead(A0) * 0.48876;
  
  dtostrf(celsius, 0, 2, strSuhu);
  
  // Penanganan gambar
  u8g.firstPage();  
  do 
  {
    buatGambar();
  } while( u8g.nextPage());
  
  delay(1000); // Tunda 1 detik
}

void buatGambar() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 20, "Suhu (Celsius):");
  
  u8g.setFont(u8g_font_osb21);
  u8g.drawStr(0, 45, strSuhu);
}

