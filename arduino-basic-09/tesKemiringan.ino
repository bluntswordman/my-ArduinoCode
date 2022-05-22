// Contoh penggunaan sensor kemiringan

const byte PIN_SENSOR = 2;
const byte PIN_LED = 3;

void setup() 
{
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_LED, OUTPUT); 
}

void loop() 
{
  int nilaiSensor = digitalRead(PIN_SENSOR);
  
  if (nilaiSensor == LOW)
    digitalWrite(PIN_LED, HIGH);
  else
    digitalWrite(PIN_LED, LOW);
   
  delay(100);
 }

