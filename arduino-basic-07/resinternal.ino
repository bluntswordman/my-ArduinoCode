// Contoh penggunaan tombol
//   untuk mengontrol LED
//   menggunakan resistor internal

const int PIN_LED = 4;
const int PIN_TOMBOL = 2;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);
}

void loop()
{
  int keadaanTombol = digitalRead(PIN_TOMBOL);
  digitalWrite(PIN_LED, not keadaanTombol);
}

