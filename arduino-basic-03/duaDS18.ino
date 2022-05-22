// Contoh pengukuran suhu dengan sensor DS18B20
//   yang melibatkan dua sensor

#include "OneWire.h"
#include "DallasTemperature.h"

const byte PIN_DS18 = 3;
const byte SENSOR_PERTAMA = 0;
const byte SENSOR_KEDUA = 1;
              
OneWire ds(PIN_DS18);
DallasTemperature sensor(&ds);

void setup() 
{
  Serial.begin(9600);
  
  // Inisialisasi sensor
  sensor.begin();
}

void loop() 
{
  sensor.requestTemperatures();
  float celsiusA = sensor.
    getTempCByIndex(SENSOR_PERTAMA);
  float celsiusB = 
    sensor.getTempCByIndex(SENSOR_KEDUA);

  Serial.print("Sensor pertama: ");
  Serial.print(celsiusA);
  Serial.print(", sensor kedua: ");
  Serial.println(celsiusB);
  
  delay(500);
}

