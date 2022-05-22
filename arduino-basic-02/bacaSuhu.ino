// Contoh untuk membaca file suhu.csv

#include <SD.h>

const byte PIN_CS = 53;

char NAMAFILE[] = "suhu.csv";

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_CS, OUTPUT);
  
  if (!SD.begin(PIN_CS))
  {
    Serial.println("Problem di SD card!");
    return;
  }
}

void loop()
{
  char data[24];
  
  File fileCSV = SD.open(NAMAFILE, FILE_READ);  
  if (!fileCSV)
  {
     Serial.println("Tak dapat membuka file!");
     return; 
  }
 
  while (fileCSV.available())
  {
    // Baca sampai sebelum newline
    int jumByte = fileCSV.readBytes(data, 24);
    data[jumByte - 2] = 0; // Karakter NULL
    
    // Tampilkan utuh
    Serial.println(data);
    
    // Pecah menjadi tiga data
    char jam[9];
    char sensor[9];
    char suhu[5];
    
    strncpy(jam, data, 8);
    jam[8] = 0;  // Karakter NULL
    
    strncpy(sensor, data + 9, 8);
    sensor[8] = 0;  // Karakter NULL

    strncpy(suhu, data + 16, 4);
    suhu[4] = 0;  // Karakter NULL

    Serial.print("Jam: ");
    Serial.print(jam);
    Serial.print(", Sensor: ");
    Serial.print(sensor);
    Serial.print(", Suhu: ");
    Serial.println(suhu);
  }
  
  Serial.println("-------------------------------");
 
  delay(5000);
}

