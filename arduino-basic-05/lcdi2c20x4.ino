// Contoh penggunaan LCD jenis I2C 20 x 4 karakter

#include <LiquidCrystal.h>

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"


LiquidCrystal_I2C lcd(0x27, 20, 4);  // Alamat LCD adalah 0x27
                                     // Mengandung 20 kolom dan
                                     // 4 baris

void setup()
{
  // Inisialisasi LCD
  lcd.begin();  
}

void loop()
{
  lcd.clear();
  lcd.print("Percobaan LCD 20 x 4");
  lcd.setCursor(0, 1);
  lcd.print("memakai Arduino Mega");
  lcd.setCursor(0, 2);
  lcd.print("Ini baris ketiga");
  lcd.setCursor(4, 3);
  lcd.print("Baris keempat ya");
  
  delay(1000);
}

