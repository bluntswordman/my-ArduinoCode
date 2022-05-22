// Contoh pengujian OLED

#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g; 

void setup() 
{
}

void loop() 
{
  // Penanganan gambar
  u8g.firstPage();  
  do 
  {
    buatGambar();
  } while( u8g.nextPage());
  
  delay(50); // Tunda sebentar sebelum menyegarkan gambar
}

void buatGambar() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 22, "Ujicoba OLED");
  u8g.drawStr(0, 35, "menggunakan");

  u8g.setFont(u8g_font_osb21);
  u8g.drawStr(10, 57, "Arduino");
}

