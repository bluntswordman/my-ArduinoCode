// Contoh pengujian sensor DHT11

#include "dht.h"

const byte PIN_SENSOR_DHT11 = 2;

dht sensorDHT;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  sensorDHT.read11(PIN_SENSOR_DHT11);
  
  Serial.print("Kelembaban udara = ");
  Serial.print(sensorDHT.humidity);
  Serial.println("%");
  Serial.print("Suhu = "); 
  Serial.println(sensorDHT.temperature);
  
  delay(1000); // Diperlukan oleh DHT11 
}

