// Contoh penggunaan LCD 20 x 4 karakter

#include <LiquidCrystal.h>

const byte PIN_RS   = 12;
const byte PIN_E    = 11;
const byte PIN_DB_4 = 7;
const byte PIN_DB_5 = 6;
const byte PIN_DB_6 = 5;
const byte PIN_DB_7 = 4;

// Buat objek LCD
LiquidCrystal lcd(PIN_RS, PIN_E, PIN_DB_4, 
                  PIN_DB_5, PIN_DB_6, PIN_DB_7);

void setup()
{
  // Tentukan ukuran LCD
  lcd.begin(20, 4);  
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

