// -------------------------------------
// Pengontrolan motor DC
//    menggunakan motor driver L298
// -------------------------------------

const byte PIN_IN1 = 2;
const byte PIN_IN2 = 3;
const byte PIN_POTENSIO = A0;
const byte PIN_ENABLE = 44;

void setup()
{
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);  
  pinMode(PIN_ENABLE, OUTPUT);
}

void loop()
{
  // Atur kecepatan
  int nilai = analogRead(PIN_POTENSIO);
  analogWrite(PIN_ENABLE, nilai / 4);
  
  // Putar motor ke satu arah
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);  
  delay(3000);
  
  // Hentikan motor
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  delay(1000);
  
  // Putar ke arah lain
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);  
  delay(3000); 
  
  // Hentikan motor
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  delay(1000);
}

