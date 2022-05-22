// Contoh untuk membentuk file CSV
//   di SD card

#include <SD.h>

const byte PIN_CS = 53;

char NAMAFILE[] = "suhu.csv";
File fileCSV;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_CS, OUTPUT);
  
  if (!SD.begin(PIN_CS))
  {
    Serial.println("Problem di SD card!");
    return;
  }

  // Hapus file kalau ada
  if (SD.exists(NAMAFILE))
    SD.remove(NAMAFILE);

  // Simpan ke file suhu.csv
  // 1. Buka file untuk penyimpanan data
  fileCSV = SD.open(NAMAFILE, FILE_WRITE);  
  if (!fileCSV)
  {
     Serial.println("File suhu.csv tidak dapat dibuka!");
     return; // Akhiri setup()
  }
  
  // 2. Tulis data ke SD card
  simpanData("20:30:01", "Sensor 1", 30.2);
  simpanData("20:30:01", "Sensor 2", 29.8);
  simpanData("20:30:02", "Sensor 1", 30.2);
  simpanData("20:30:02", "Sensor 2", 30.0);
  simpanData("20:30:03", "Sensor 1", 30.1);
  simpanData("20:30:03", "Sensor 2", 29.8);
  
  // 3. Tutup file
  fileCSV.close();

  Serial.println("Data sudah disimpan!");
}

void loop()
{

}

void simpanData(char *jam, char *sensor, float suhu)
{
  char data[80];
  char strSuhu[6];
  
  sprintf(data, "%8s,%8s,", jam, sensor);
  dtostrf(suhu, 4, 1, strSuhu);
  strcat(data, strSuhu);

  fileCSV.println(data);
}


