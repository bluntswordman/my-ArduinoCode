// Contoh untuk menampilkan simbol

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

const byte DERAJAT = B11011111;
const byte PANAH_KANAN = B01111110;

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Alamat LCD adalah 0x27
                                     // Mengandung 20 kolom dan
                                     // 4 baris

void setup()
{
  lcd.begin();

  // Tampilkan beberapa karakter melalui write
  lcd.clear();
  lcd.print("Suhu ");
  lcd.write(PANAH_KANAN);
  lcd.write(32);
  lcd.print(23.4);
  lcd.write(DERAJAT);

  // Tampilkan karakter bernilai 200 + 2015
  lcd.setCursor(0, 1);
  for (int nilai = 0; nilai < 16; nilai++)
    lcd.write(200 + nilai);
}

void loop()
{

}

