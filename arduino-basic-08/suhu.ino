// Contoh pengukuran suhu
//   dengan sensor LM35DZ

const int PIN_SUHU = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float celsius = analogRead(PIN_SUHU) * 0.48876;
  Serial.println(celsius);

  delay(500);  // Tunda sebentar 
}

