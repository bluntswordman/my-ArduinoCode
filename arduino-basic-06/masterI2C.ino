// Pengiriman data dari Arduino Mega
//   ke Arduino Uno

#include <Wire.h>

const int ALAMAT = 4;

void setup()
{
   Wire.begin();
}
void loop()
{
  for (byte data = 0; data < 256; data++)
  {
    // Kirim data
    Wire.beginTransmission(ALAMAT); 
    Wire.write(data);
    Wire.endTransmission();

    delay(1000); // Tunda 1 detik
  }
}

