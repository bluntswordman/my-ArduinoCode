// Contoh penggunaan Wire
//   untuk mengakses waktu pada modul RTC

#include <Wire.h>

const byte ALAMAT_RTC = 0x68; 
const byte JUMLAH_BYTE = 7; 

String namaHari[] = {"", "Minggu", "Senin", "Selasa",
                     "Rabu", "Kamis", "Jumat", "Sabtu"};

int jam, menit, detik;
int hari, kodeHari, bulan, tahun;

void setup()  
{
  Serial.begin(9600);
  Wire.begin();

  // Atur waktu
  byte dataWaktu[] = {30, 15, 8, 7, 24, 6, 17};

  for (int j = 0; j < 7; j++)
    dataWaktu[j] = desKeBCD(dataWaktu[j]);
  
  Wire.beginTransmission(ALAMAT_RTC);
  Wire.write(0);
  Wire.write(dataWaktu, 7);
  Wire.endTransmission();

  delay(2000);
}

void loop()
{
  Wire.beginTransmission(ALAMAT_RTC);
  Wire.write(0x00);
  Wire.endTransmission();
  
  // Permintaan untuk mengakses data
  //   pada modul RTC
  Wire.requestFrom(ALAMAT_RTC, JUMLAH_BYTE);
  detik    = bcdKeDes(Wire.read() & 0x7f);
  menit    = bcdKeDes(Wire.read());
  jam      = bcdKeDes(Wire.read() & 0x3f);  
  kodeHari = bcdKeDes(Wire.read() );
  hari     = bcdKeDes(Wire.read());
  bulan    = bcdKeDes(Wire.read());
  tahun    = bcdKeDes(Wire.read());
  tahun    = tahun + 2000; 
  
  infoWaktu(); 
  delay(1000);
}

// Konversi BCD ke desimal
byte bcdKeDes(byte bilangan)
{
  return ((bilangan / 16 * 10) + (bilangan % 16));
}

// Konversi desimal ke BCD
byte desKeBCD(byte bilangan)
{
  return  (bilangan / 10 * 16 + (bilangan % 10));
}

// Penyajian waktu
void infoWaktu()
{
  Serial.print(namaHari[kodeHari]);
  Serial.print(", ");
  Serial.print(hari);
  Serial.print(" ");
  Serial.print(bulan);
  Serial.print(" ");
  Serial.print(tahun);

  Serial.print(" ");
  tampilkanAngka(jam);
  Serial.print(":");
  tampilkanAngka(menit);
  Serial.print(":");
  tampilkanAngka(detik);
  Serial.println();
}

// Penyajian angka menjadi 2 digit 
void tampilkanAngka(int angka){
  if(angka < 10)
    Serial.print('0');
    
  Serial.print(angka);
}

