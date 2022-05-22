// Contoh pengaturan intensitas LED

const byte PIN_LED = 44;
const byte PIN_POTENSIO = A0;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  int nilaiPinA0 = analogRead(PIN_POTENSIO);

  analogWrite(PIN_LED, nilaiPinA0 / 4);
}

