// Contoh pembacaan suhu dengan 
//   sensor suhu inframerah GY-906

#include <Wire.h>
#include "MLX90614.h"
using namespace esl;

MLX90614 sensor;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();  
  sensor.init();
}

void loop() 
{
  float celsius;
  
  celsius = sensor.readAmbientTemperature(); // Suhu ambient 
  if (!sensor.is_crc_error()) 
  {
    Serial.print("Suhu Ambient (Ta): ");
    Serial.println(celsius);
  }
  
  celsius = sensor.readObjectTemperature(); // suhu objek
  if (!sensor.is_crc_error()) 
  {
    Serial.print("Suhu objek (To): ");
    Serial.println(celsius);
  }
  
  delay(1000);
}


