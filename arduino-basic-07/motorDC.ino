// Pengontrolan kecepatan motor DC
//   menggunakan transistor dan potensiometer

const byte PIN_BASIS = 44;
const byte PIN_POTENSIO = A0;

void setup()
{
   Serial.begin(9600);
   pinMode(PIN_BASIS, OUTPUT);  
}

void loop()
{
  // Baca pin A0
  int nilai = analogRead(PIN_POTENSIO);
  Serial.println(nilai);
  
  // Atur kecepatan motor
  analogWrite(PIN_BASIS, nilai / 4);
}

