// Contoh penggunaan sensor TCR5000 YL-54

const byte PIN_ANALOG = A0;
const byte PIN_DIGITAL = 2;

void setup() 
{
  Serial.begin(9600); 
  pinMode(PIN_DIGITAL, INPUT); 
}

void loop() 
{
  int nilaiDigital = digitalRead(PIN_DIGITAL);
  int nilaiAnalog = analogRead(PIN_ANALOG);

  Serial.print("D0 = ");
  Serial.print(nilaiDigital);
  Serial.print(", A0 = ");
  Serial.println(nilaiAnalog);
  
  delay(500);
}

