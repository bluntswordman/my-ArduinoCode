// Contoh untuk menguji modul tombol tekan

const int PIN_LED = 4;
const int PIN_TOMBOL = 2;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TOMBOL, INPUT);
}

void loop() 
{
  int keadaanTombol = digitalRead(PIN_TOMBOL);
  digitalWrite(PIN_LED, keadaanTombol);  
}

