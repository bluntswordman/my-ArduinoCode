// Contoh penggunaan LDR
//   untuk mematikan atau menyalakan LED

const byte PIN_LDR = A0;
const byte PIN_LED = 4;
const int AMBANG = 700;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  int nilaiLDR = analogRead(PIN_LDR);
  Serial.println(nilaiLDR);

  if (nilaiLDR >= AMBANG)
    digitalWrite(PIN_LED, HIGH);
  else
      digitalWrite(PIN_LED, LOW);  
}

