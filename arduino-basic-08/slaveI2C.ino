// Arduino Uno sebagai slave
//   yang menerima data melalui I2C

#include <Wire.h>

const int ALAMAT = 4;  

void setup()
{
  Serial.begin(9600);
  Wire.begin(ALAMAT); 

  // Penanganan kejadian kejadian data diterima
  Wire.onReceive(kejadianPenerimaan);

  Serial.println("Siap menerima data...");
}

void loop()
{
  
}

void kejadianPenerimaan()
{
  while(Wire.available() > 0)
  {
    byte data = Wire.read(); 
    Serial.println(data);
  }
}

