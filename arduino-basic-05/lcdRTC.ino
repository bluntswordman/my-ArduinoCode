// Percobaan untuk menampilkan informasi waktu
//   pada modul RTC ke LCD

#include <Wire.h> 
#include "RTClib.h"
#include "LiquidCrystal_I2C.h"

String namaHari[] = 
{ 
  "Minggu", "Senin", "Selasa", "Rabu", 
  "Kamis", "Jumat", "Sabtu"
};

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat LCD adalah 0x27
                                     // Mengandung 16 kolom dan
                                     // 2 baris
void setup()
{
  lcd.begin();                      // Inisialisasi LCD 
}

void loop()
{
  DateTime kini = rtc.now();
  String baris1, baris2;
  
  // Baca data di RTC

  baris1 = namaHari[kini.dayOfTheWeek()] + " " +
           String(kini.day()) + "/" + 
           String(kini.month()) + "/" + 
           String(kini.year());

  lcd.clear();         
  lcd.print(baris1);

  baris2 = formatDuaDigit(kini.hour()) + ":" +
           formatDuaDigit(kini.minute()) + ":" +
           formatDuaDigit(kini.second());
             
  lcd.setCursor(0, 1);
  lcd.print(baris2);
  
  delay(1000);
}

String formatDuaDigit(int bil)
{
  if (bil < 10 && bil >= 0)
    return ("0" + String(bil));
  else
    return String(bil);  
}

