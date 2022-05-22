// Contoh pengukuran suhu dengan sensor DS18B20

#include "OneWire.h"
#include "DallasTemperature.h"

const byte PIN_DS18 = 3;
const byte SENSOR_PERTAMA = 0;
              
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
  float celsius = sensor.
    getTempCByIndex(SENSOR_PERTAMA);

  Serial.print("Suhu (Celsius): ");
  Serial.println(celsius);
  
  delay(500);
}

