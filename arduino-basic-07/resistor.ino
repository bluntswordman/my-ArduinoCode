// Contoh untuk mengukur hambatan
//   suatu resistor

const byte PIN_RESISTOR = A0;
   
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int nilaiPinA0 = analogRead(PIN_RESISTOR);
  float vOut = nilaiPinA0 * 5.0 / 1023;
  float hambatan = 10000 * vOut / (5.0 - vOut);
  if (hambatan != 0)
  {
    Serial.print("Resistor: ");
    Serial.println(hambatan);
    delay(500);
  }  
}

