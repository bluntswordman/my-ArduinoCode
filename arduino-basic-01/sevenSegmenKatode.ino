// Contoh penyajian angka 
//   pada tujuh segmen common cathode

const byte SEGMEN[10] =
{
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110   // 9
};

const byte PIN_SEGMEN[8] = {5, 6, 7, 8, 9, 10, 11, 12};

void setup()
{
  Serial.begin(9600);
  
  // Inisialisasi pin segmen
  for (int j = 0; j < 8; j++)
    pinMode(PIN_SEGMEN[j], OUTPUT);
}

void loop()
{
  // Tampilkan 0 s/d 9
  for (int j = 0; j < 10; j++)
  {
    Serial.println(j);
    tampilkanAngka(j);
    delay(2000);
  }

  delay(3000);  
}

void tampilkanAngka(int angka)
{
  // Abaikan kalau angka tidak antara 0 dan 9
  if ((angka < 0) || (angka > 9))
    return;
    
  byte dataSegmen = SEGMEN[angka];
  for (int j = 0; j < 8; j++)
  {
    int bit = bitRead(dataSegmen, 7-j);
  
    if (bit == HIGH)   
      digitalWrite(PIN_SEGMEN[j], HIGH);
    else
      digitalWrite(PIN_SEGMEN[j], LOW);
  }  
}

