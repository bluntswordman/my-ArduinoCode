// Pengujian pustaka RTClib
//   untuk modul yang menggunakan DS1307

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

String namaHari[] = 
{ 
  "Minggu", "Senin", "Selasa", "Rabu", 
  "Kamis", "Jumat", "Sabtu"
};

void setup () 
{
  Serial.begin(9600);
 
  if (! rtc.begin()) {
    Serial.println("RTC tidak dikenal");
    while (1);
  }

  // Atur waktu sesuai dengan waktu di komputer
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () 
{
  DateTime kini = rtc.now();
    
  Serial.print(kini.year());
  Serial.print('/');
  Serial.print(kini.month());
  Serial.print('/');
  Serial.print(kini.day());
  Serial.print(" (");
  Serial.print(namaHari[kini.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(kini.hour());
  Serial.print(':');
  Serial.print(kini.minute());
  Serial.print(':');
  Serial.print(kini.second());
  Serial.println();
    
  delay(1000);
}

