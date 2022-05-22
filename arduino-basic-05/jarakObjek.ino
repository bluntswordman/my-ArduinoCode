// Pengukuran jarak pada HC-SR04
//   dengan memanfaatkan pulseIn()

const byte PIN_TRIG = 13;
const byte PIN_ECHO = 12;

void setup() 
{
  Serial.begin (9600);
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() 
{
  // Kirim isyarat HIGH selama 10 mikrodetik
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);  // Tunda 10 mikrodetik 
  digitalWrite(PIN_TRIG, LOW);
  
  // Baca hasilnya di pin echo
  double selang = pulseIn(PIN_ECHO, HIGH);
  
  // Hitung jarak yang diperoleh
  double jarak = 0.0343 * ( selang / 2);
  
  if (jarak > 300 || jarak <= 0) 
  {
    Serial.println("di luar jangkauan sensor");
  }
  else 
  {
    Serial.print(jarak);
    Serial.println(" cm");
  }
  
  delay(1000); // Tunda satu detik
}

