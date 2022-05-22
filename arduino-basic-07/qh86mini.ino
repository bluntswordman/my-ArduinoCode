// Contoh pengujian modul QH86 mini
//   untuk mengontrol kecepatan motor DC

const byte PIN_IN1 = 44;
const byte PIN_IN2 = 45;
const byte PIN_POTENSIO = A0;

void setup() 
{
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
}

void loop() 
{
  // Baca nilai pada pin A0
  int nilaiPin = analogRead(PIN_POTENSIO);

  // Tentukan nilai penentu kecepatan
  int nilaiKecepatan = nilaiPin / 4;
  
  // Putar motor ke suatu arah
  analogWrite(PIN_IN1, nilaiKecepatan);
  digitalWrite(PIN_IN2, LOW);
  delay(3000);

  // Hentikan putaran
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  delay(1000);

  // Putar ke arah lain
  digitalWrite(PIN_IN1, LOW);
  analogWrite(PIN_IN2, nilaiKecepatan);
  delay(3000);

  // Hentikan putaran
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  delay(1000);
}

