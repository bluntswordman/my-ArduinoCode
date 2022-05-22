// Contoh penggunaan LCD grafik QC12864B

#include "U8glib.h"

const byte PIN_CS = 53;

U8GLIB_ST7920_128X64_4X u8g(PIN_CS); 

void setup()
{ 
}

void loop()
{
  // Gambar pertama
  u8g.firstPage();
  do 
  {
     buatGambar();
  } while (u8g.nextPage());   
 
  delay(2000);  

  // Gambar kedua
  u8g.firstPage();
  do 
  {
     buatGambar2();
  } while (u8g.nextPage());   
 
  delay(2000);  
}

void buatGambar()
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 10, "Uji LCD Grafik");
  u8g.drawStr(0, 22, "via Arduino Mega");
  u8g.drawStr(20, 50, "Yes, Bisa!"); 
}

void buatGambar2()
{
  u8g.setFont(u8g_font_gdb17r);
  u8g.drawStr(30, 20, "Lega"); 
  u8g.drawStr(10, 40, "Rasanya!");  
}
