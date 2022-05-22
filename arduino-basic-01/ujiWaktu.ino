// Contoh pengaksesan waktu
//   menggunakan pustaka Time

#include "TimeLib.h"

void setup()
{
  Serial.begin(9600); 

  setTime(10, 30, 00, 1, 12, 2020);
}

void loop()
{
  time_t waktu = now();
  tampilkanWaktu(waktu);
 
  delay(1000);  
}

void tampilkanWaktu(time_t waktu)
{
  int tg = day(waktu);
  int bl = month(waktu);
  int th = year(waktu);
  int jam = hour(waktu);
  int menit = minute(waktu);
  int detik = second(waktu);
  
  Serial.print(tg);
  Serial.print("/");
  Serial.print(bl);
  Serial.print("/");
  Serial.print(th);
  
  Serial.print(" ");
  
  tampil2digit(jam);
  Serial.print(':');
  tampil2digit(menit);
  Serial.print(':');
  tampil2digit(detik);
  Serial.println();
}

void tampil2digit(int bil)
{
  if (bil < 10 && bil >= 0)
    Serial.print('0');
  
  Serial.print(bil);  
}

