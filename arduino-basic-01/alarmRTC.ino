// Contoh penggunaan alarm

#include "TimeLib.h"
#include "TimeAlarms.h"
#include <Wire.h>
#include "RTClib.h"

const byte PIN_LED = 8;
const int INTERVAL_LED = 4000;

unsigned long waktuAwal = millis();
boolean led_hidup = false;

RTC_DS1307 rtc;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);

  if (!rtc.begin())
  {
    Serial.println("RTC tidak dikenal!");
    while (true);
  }
  
  // Sinkronisasi waktu
  setSyncProvider(syncProvider);

  // Tentukan alarm
  Alarm.timerRepeat(10, aktifkanLED);       
  
  Serial.println("Penjadualan telah dilakukan...");
}

void  loop()
{  
  tampilkanJam();

  if (led_hidup)
    if (abs(millis() - waktuAwal) > INTERVAL_LED)    
    {
      led_hidup = false;  
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED dimatikan");
    }
    
  Alarm.delay(1000); // Tunggu satu detik
}

// Fungsi yang dijalankan per 10 detik
void aktifkanLED()
{
  waktuAwal = millis();
  led_hidup = true;
  Serial.println("LED dihidupkan");
  digitalWrite(PIN_LED, HIGH);       
}

void tampilkanJam()
{
  tampil2digit(hour());
  Serial.print(':');
  tampil2digit(minute());
  Serial.print(':');
  tampil2digit(second());
  Serial.println();
}

void tampil2digit(int bil)
{
  if (bil < 10 && bil >= 0)
    Serial.print('0');
  
  Serial.print(bil);  
}

uint32_t syncProvider()
{
  return rtc.now().unixtime();
}
