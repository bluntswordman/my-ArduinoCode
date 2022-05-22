// Contoh penggunaan pengukuran
//   tegangan pada kaki tengah
//   potensiometer

const byte PIN_POTENSIO = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int nilaiPin = analogRead(PIN_POTENSIO);
  float tegangan = nilaiPin * 5.0 / 1023;

  Serial.print("Nilai pin: ");
  Serial.print(nilaiPin);
  Serial.print(", tegangan: ");
  Serial.print(tegangan);
  Serial.println(" volt");
}

