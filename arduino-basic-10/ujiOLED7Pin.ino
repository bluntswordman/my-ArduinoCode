// Percobaan OLED 7 pin

#include <U8glib.h>

//----------------------- sck, mosi, cs, a0, reset
U8GLIB_SSD1306_128X64 u8g(12, 11, 8, 9, 10); 

void setup() 
{
}

void loop() 
{
  // Penanganan gambar
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage());
  
  delay(50); // Tunda sebentar sebelum menyegarkan gambar
}

void draw() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(11, 22, "OLED 7 Pin");
 
  u8g.setFont(u8g_font_osb21);
  u8g.drawStr(10, 50, "SUKSES");
}

