// Contoh penggunaan sensor inframerah
//    pendeteksi halangan

const byte PIN_SENSOR = 2;
const byte PIN_LED_HIJAU = 11;
const byte PIN_LED_MERAH = 12;

void setup() 
{
  Serial.begin(9600); 
  pinMode(PIN_SENSOR, INPUT); 
  pinMode(PIN_LED_MERAH, OUTPUT);
  pinMode(PIN_LED_HIJAU, OUTPUT); 
}

void loop() 
{
  int nilaiSensor = digitalRead(PIN_SENSOR);
  if (nilaiSensor == LOW) // Berarti ada halangan
  {
    Serial.println("LOW. LED merah menyala");
    digitalWrite(PIN_LED_MERAH, HIGH);
    digitalWrite(PIN_LED_HIJAU, LOW);
  }
  else
  {
    Serial.println("HIGH. LED hijau menyala");
    digitalWrite(PIN_LED_MERAH, LOW);
    digitalWrite(PIN_LED_HIJAU, HIGH);
  }
}

