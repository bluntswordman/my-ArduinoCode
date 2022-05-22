// Contoh penggunaan sensor PIR

const byte PIN_PIR = 3;
const byte PIN_LED = 2;

void setup() 
{
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  int nilaiPin = digitalRead(PIN_PIR);
  if (nilaiPin == HIGH)
  {
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
  }  
}

