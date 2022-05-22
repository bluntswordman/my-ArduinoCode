// Contoh penggunaan alarm

#include "TimeLib.h"
#include "TimeAlarms.h"

void setup()
{
  Serial.begin(9600);

  // Atur waktu
  setTime(23, 59, 15, 25, 06, 2017); // Hari Minggu
  
  // Tentukan alarm
  Alarm.alarmRepeat(23, 59, 25, hidupkanLampu);  // 23:59:25 setiap hari
  Alarm.alarmRepeat(23, 59, 30, matikanLampu);   // 23:59:35 setiap hari 
  Alarm.alarmRepeat(dowSunday, 23, 59, 35, 
                    susunKegiatan);              // 23:59:35 setiap Minggu 
 
  Alarm.timerRepeat(8, istirahat);   // Setiap 8 detik    
  Alarm.timerOnce(10, cekSekali);    // Sekali setelah 10 detik 
}

void  loop()
{  
  tampilkanJam();
  Alarm.delay(1000); // Tunggu satu detik
}

// Fungsi untuk mematikan Lampu
void matikanLampu()
{
  Serial.println("Lampu dimatikan");    
}

void hidupkanLampu()
{
  Serial.println("Lampu dihidupkan");           
}

// Untuk menguji timerOnce() pada hari sabtu
void susunKegiatan()
{
  Serial.println("Waktu untuk menyusun kegiatan mingguan");      
}

// Fungsi yang dijalankan per 20 detik
void istirahat()
{
  Serial.println("Sudahkah istirahat sebentar?");       
}

// Dijalankan sekali
void cekSekali()
{
  Serial.println("Hanya dijalankan sekali");         
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

