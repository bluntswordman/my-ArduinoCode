// Contoh untuk membuat berbagai bentuk
//   pada LCD

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
  // Buat dua kotak 
  u8g.drawBox(40, 50, 10, 10);
  u8g.drawBox(50, 40, 19, 20);
  u8g.drawBox(70, 40, 50, 20);

  // Buat segitiga
  u8g.drawTriangle(50, 40, 40, 50, 50, 50);

  // Buat lingkaran
  u8g.drawDisc(50, 58, 5);
  u8g.drawDisc(80, 58, 5);
  u8g.drawDisc(105, 58, 5);
  
  // Buat garis
  u8g.drawVLine(69, 56, 4);   // Sambungan truk
  u8g.drawHLine(2, 63, 125); // Jalan
    
  // Buat lingkaran dan garis
  u8g.drawCircle(20, 20, 10);   // Matahari
  u8g.drawLine(10, 10, 12, 12); // Pancaran matahari
  u8g.drawLine(30, 30, 28, 28); // Pancaran matahari
  u8g.drawLine(30, 10, 28, 12); // Pancaran matahari
  u8g.drawLine(10, 30, 12, 28); // Pancaran matahari
  
  delay(1000);
}


