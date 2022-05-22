// Percobaan pada OLED 6 pin

#include <U8glib.h>

// -------------------- SCL, SDA, dummy, D/C, RST 
U8GLIB_SH1106_128X64 u8g(2, 3, 4, 5, 6);  

void setup() 
{
}

void loop() 
{
  // Penanganan gambar
  u8g.firstPage();  
  do {
    buatGambar();
  } while( u8g.nextPage());
  
  delay(50); // Tunda sebentar sebelum menyegarkan gambar
}

void buatGambar() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(11, 22, "OLED 6 pin");
 
  u8g.setFont(u8g_font_osb21);
  u8g.drawStr(10, 50, "SUKSES");
}

