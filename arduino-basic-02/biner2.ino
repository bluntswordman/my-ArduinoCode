// Contoh pengontrolan IC 74HC595
//   untuk menyajikan kode biner
//   TANPA menggunakan SPI

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
    
    // Proses bit demi bit
    for (int posisi_bit = 7; posisi_bit >= 0; posisi_bit--)
    {
      int bit = bitRead(data, posisi_bit);
      digitalWrite(PIN_DATA, bit);
     
      // Kirim bit ke storage register
      digitalWrite(PIN_CLOCK, HIGH);
      digitalWrite(PIN_CLOCK, LOW);
    }
    
    // Kirim data secara paralel
    digitalWrite(PIN_LATCH, HIGH);
    delay(1000);
  }  
}

