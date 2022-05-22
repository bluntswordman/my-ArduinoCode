// Contoh pengujian modul KY-010

const byte PIN_SENSOR = 2;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_SENSOR, INPUT);
}

void loop() 
{
  int nilai = digitalRead(PIN_SENSOR);
  Serial

