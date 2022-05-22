// Contoh pembuatan bitmap

#include "U8glib.h"

const byte PIN_CS = 53;

U8GLIB_ST7920_128X64_4X u8g(PIN_CS);

const byte bitmap_loko[] =
{
  B00001111,
  B00101001,
  B00101001,
  B11111111,
  B11111111,
  B11111111,
  B10101010,
  B01010100
};

const byte bitmap_gerbong[] =
{
  B01111111,
  B01001001,
  B01001001,
  B01111111,
  B11111111,
  B11111111,
  B01010101,
  B00101010
};

int pos = 128;

void setup()
{
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);  
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
  u8g.drawBitmap(pos, 40, 1, 8, bitmap_loko);
  u8g.drawBitmap(pos + 8, 40, 1, 8, bitmap_gerbong);
  u8g.drawBitmap(pos + 16, 40, 1, 8, bitmap_gerbong);
  u8g.drawBitmap(pos + 24, 40, 1, 8, bitmap_gerbong);
    
  pos = pos - 4;;
  if (pos <= -24)
    pos = 128; 
}

