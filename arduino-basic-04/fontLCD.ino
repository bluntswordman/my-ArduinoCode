// Contoh penggunaan beberapa font

#include "U8glib.h"

const byte PIN_CS = 53;

U8GLIB_ST7920_128X64_4X u8g(PIN_CS);

void setup()
{
    
}

void loop()
{
  u8g.firstPage();
  do 
  {
     buatGambar();
  } while (u8g.nextPage());   
 
  delay(1000);  
}

void buatGambar()
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 10, "unifont");
  
  u8g.setFont(u8g_font_u8glib_4);
  u8g.drawStr(0, 22, "u8glib_4");

  u8g.setFont(u8g_font_gdb17r);
  u8g.drawStr(0, 50, "gdb17r"); 
}

