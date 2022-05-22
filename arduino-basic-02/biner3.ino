// Contoh pengontrolan IC 74HC595
//   untuk menyajikan kode biner
//   TANPA menggunakan SPI
//   tetapi menggunakan shoftOut()

const byte PIN_LATCH = 7;  
const byte PIN_DATA  = 5;  
const byte PIN_CLOCK = 6;  

void setup()
{
  Serial.begin(9600);
  
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
}

void loop()
{
  for (byte data = 0; data < 256; data++)
  {
    Serial.println(data);
    
    // Memperbolehkan pengiriman data
    digitalWrite(PIN_LATCH, LOW);
    
    shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, data);
    
    // Kirim data secara paralel
    digitalWrite(PIN_LATCH, HIGH);
    delay(1000);
  }  
}

