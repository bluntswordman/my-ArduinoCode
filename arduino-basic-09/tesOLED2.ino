// Contoh pengujian OLED beresolusi 128 x 32

#include "U8glib.h"

U8GLIB_SSD1306_128X32 u8g; 

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
  u8g.drawStr(0, 15, "Ujicoba OLED");
  u8g.drawStr(0, 30, "128 x 32 dot");
}

