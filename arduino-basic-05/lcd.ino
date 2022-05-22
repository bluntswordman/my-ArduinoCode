
// Percobaan untuk menampilkan informasi
//   dengan I2C LCD 16 x 2

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat LCD adalah 0x27
                                     // Mengandung 16 kolom dan
                                     // 2 baris
void setup()
{
  lcd.begin();                      // Inisialisasi LCD 
}

void loop()
{
  lcd.clear();
  lcd.print("Uji coba dengan");
  lcd.setCursor(0, 1);
  lcd.print("Arduino Mega ***");

  delay(1000);
}

