// Contoh pembuatan simbol

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Alamat LCD adalah 0x27
                                     // Mengandung 20 kolom dan
                                     // 4 baris

byte huruf_C[] =
{
  B01110, B01001, B01000, B01000, B11000, B11000, B11001, B11111
};

byte huruf_E[] =
{
  B01110, B01001, B01000, B01000, B11100, B11000, B11001, B11110
};

byte huruf_R[] =
{
  B01110, B01001, B01001, B01001, B11110, B11100, B11010, B11001
};

byte huruf_I[] =
{
  B00100, B00100, B00100, B00100, B01100, B01100, B01100, B01100
};

byte huruf_A[] = 
{
  B01110, B01010, B01010, B01010, B111111, B11001, B11001, B11001
}; 

void setup()
{
  // Inisialisasi LCD
  lcd.begin();

  // Buat karakter
  lcd.createChar(0, huruf_C);
  lcd.createChar(1, huruf_E);
  lcd.createChar(2, huruf_R);
  lcd.createChar(3, huruf_I);
  lcd.createChar(4, huruf_A);
  
  // Tampilkan beberapa karakter melalui write
  lcd.clear(); 
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
}

void loop()
{

}


