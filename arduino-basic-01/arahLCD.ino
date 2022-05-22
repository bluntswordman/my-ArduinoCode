// Contoh pengaturan arah tulisan

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
  u8g.setFont(u8g_font_6x12r);
  u8g.drawStr(20, 10, "drawStr()");
  u8g.drawStr90(0, 0, "drawStr90()"); 
  u8g.drawStr180(80, 50, "drawStr180()"); 
  u8g.drawStr270(100, 60, "drawStr270()"); 
}

