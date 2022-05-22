// Contoh untuk memantau saklar sentuh

const int PIN_SAKLAR = 2;   

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_SAKLAR, INPUT);
}

void loop() 
{
  int keadaanSaklar = digitalRead(PIN_SAKLAR);
  Serial.println(keadaanSaklar);
}

