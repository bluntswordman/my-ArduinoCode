// Contoh penggunaan potensiometer
//   untuk menyalakan atau mematikan LED

const byte PIN_POTENSIO = A0;
const byte PIN_LED = 4;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  int nilaiPin = analogRead(PIN_POTENSIO);
  if (nilaiPin >= 512)
    digitalWrite(PIN_LED, HIGH);
  else
    digitalWrite(PIN_LED, LOW);  
}

