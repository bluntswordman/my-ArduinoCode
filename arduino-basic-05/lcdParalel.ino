// Contoh penggunaan LCD paralel

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
  lcd.begin(16, 2);  
}

void loop()
{
  lcd.clear();
  lcd.print("Ujicoba LCD 16x2");
  lcd.setCursor(0, 1);
  lcd.print("via Arduino Mega");

  delay(1000);
}

