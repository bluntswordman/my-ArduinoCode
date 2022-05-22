// Contoh pengujian FSR

const byte PIN_ANALOG = A0;
   
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int nilaiFSR = analogRead(PIN_ANALOG);

  Serial.println(nilaiFSR);
}

