// Contoh penggunaan sensor magnetic reed

const byte PIN_SENSOR = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_SENSOR, INPUT);
}
 
void loop() 
{
  int nilaiSensor = digitalRead(PIN_SENSOR);
  
  Serial.println(nilaiSensor);

  delay(100);
}

