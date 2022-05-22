// Contoh untuk menampilkan suhu ke LCD

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

const byte DERAJAT = B11011111;

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
  float celcius = analogRead(A0) * 0.48876;
  float reaumur = 0.8 * celcius;
  float fahrenheit = 9 / 4.0 * celcius + 32;
  
  lcd.clear();
  lcd.print("Suhu sekarang:");
  
  lcd.setCursor(0, 1);
  lcd.print(celcius, 2);
  lcd.write(DERAJAT);
  lcd.print("C");

  lcd.setCursor(0, 2);
  lcd.print(reaumur, 2);
  lcd.write(DERAJAT);
  lcd.print("R");

  lcd.setCursor(0, 3);
  lcd.print(fahrenheit, 2);
  lcd.write(DERAJAT);
  lcd.print("F");

  delay(1000);
}


