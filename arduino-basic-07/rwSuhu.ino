// Contoh untuk menyimpan dan membaca data suhu

#include <SD.h>
#include <Wire.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#include <DS1307RTC.h>

const byte PIN_SUHU = A0;
const byte PIN_CS = 53;

char NAMAFILE[] = "datasuhu.csv";
AlarmID_t ID_alarm;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_CS, OUTPUT);
  
  if (!SD.begin(PIN_CS))
  {
    Serial.println("Problem di SD card!");
    while (true);
  }

  // Set Timer per 5 detik
  ID_alarm = Alarm.timerRepeat(5, simpanSuhu); 

  Serial.println("Siap memproses suhu...");
}

void loop()
{
  if (Serial.available())
  {
    String perintah = Serial.readString();
    if (perintah == "baca file")  
    {
      bacaSuhu();
    }
    else if (perintah == "hapus file")
    {
      hapusFile();
    }
  }
  
  Alarm.delay(1000);
}

void simpanSuhu()
{
  tmElements_t tm;
  
  // Baca data di RTC
  char waktu[20];
  
  if (RTC.read(tm)) 
  {
    sprintf(waktu, "%02d/%02d/%04d %02d:%02d:%02d",
            tm.Day, tm.Month, tmYearToCalendar(tm.Year),
            tm.Hour, tm.Minute, tm.Second);
    Serial.print(waktu);
  }
  else
  {
    Serial.println("Problem di RTC!");
    return;
  }
  // Baca data suhu 
  float suhu =  analogRead(PIN_SUHU) * 0.48876;
  Serial.print(",");
  Serial.println(suhu, 1);
     
  // Simpan ke file 
  // 1. Buka file untuk penyimpanan data
  File fileSuhu = SD.open(NAMAFILE, FILE_WRITE);  
  if (!fileSuhu)
  {
     Serial.println("Tak dapat membuka file!");
     return; 
  }
  
  // 2. Tulis data ke SD card
  fileSuhu.print(waktu);
  fileSuhu.print(",");
  fileSuhu.println(suhu, 1);
    
  // 3. Tutup file supaya data benar-benar disimpan
  fileSuhu.close();

}

void bacaSuhu()
{
  // Matikan alarm
  Alarm.disable(ID_alarm);
  
  // Proses untuk membaca data
  char data[26];
  
  File fileSuhu = SD.open(NAMAFILE, FILE_READ);  
  if (!fileSuhu)
  {
     Serial.println("Tak dapat membuka file!");
     return; 
  }

  Serial.println("Isi file:");
  Serial.println("-----------------------------------");
  
  while (fileSuhu.available())
  {
    int jumByte = fileSuhu.readBytes(data, 26);
    data[jumByte - 2] = 0; // Karakter NULL
    
    // Tampilkan utuh
    Serial.println(data);
  }
  
  fileSuhu.close(); 

  Serial.println("----------------------- Akhir file");
 
  // Hidupkan alarm
  Alarm.enable(ID_alarm); 
}

void hapusFile()
{
  // Matikan alarm
  Alarm.disable(ID_alarm);
  
  if (SD.exists(NAMAFILE))
  {
    SD.remove(NAMAFILE);
    Serial.println("File telah dihapus");
  }  

  // Hidupkan alarm
  Alarm.enable(ID_alarm);  
}

