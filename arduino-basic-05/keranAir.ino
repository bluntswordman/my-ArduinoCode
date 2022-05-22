// Contoh pengontrolan keran air
//   menggunakan sensor kelembapan tanah

const byte PIN_RELAI = 7;
const byte PIN_SENSOR = A0;
const int AMBANG_KELEMBAPAN = 600;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_RELAI, OUTPUT);
  digitalWrite(PIN_RELAI, LOW);
}

void loop() 
{
  int nilaiSensor = analogRead(PIN_SENSOR);
  Serial.println(nilaiSensor);
  if (nilaiSensor >= AMBANG_KELEMBAPAN)
  {
    digitalWrite(PIN_RELAI, HIGH);
    delay(8000);
    digitalWrite(PIN_RELAI, LOW);
  } 
}

