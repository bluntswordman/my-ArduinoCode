// Penggunaan tombol tekan sementara 
//   untuk menyalakan atau mematikan LED
//   secara bergantian

const int PIN_LED = 4;
const int PIN_TOMBOL = 2;

boolean ledMenyala = false;
boolean keadaanSebelum = false;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);   

  digitalWrite(PIN_LED, keadaanSebelum);  
}

void loop() 
{
  boolean keadaanTombol = digitalRead(PIN_TOMBOL);
  if (keadaanTombol == LOW && 
      keadaanTombol != keadaanSebelum)
  {
    ledMenyala = not ledMenyala;

    digitalWrite(PIN_LED, ledMenyala);
    delay(30); // Tunda sebentar 
               // untuk membuang efek pantulan
  }    
    
  keadaanSebelum = keadaanTombol; 
}

