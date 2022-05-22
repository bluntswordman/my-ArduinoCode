// Contoh pengujian sensor MQ-02

const byte PIN_DIGITAL = 2;
const byte PIN_ANALOG = 0;

void setup() 
{
  pinMode(PIN_DIGITAL, INPUT);  

  Serial.begin(9600);
}

void loop() 
{
  int nilaiAnalog = analogRead(PIN_ANALOG);
  int nilaiDigital = digitalRead(PIN_DIGITAL);

  Serial.print("D0 = ");
  Serial.print(nilaiDigital);
  Serial.print(", A0 = ");
  Serial.println(nilaiAnalog);

  delay(1000);
}

