// Contoh untuk menyalakan LED
//   secara acak
//   Versi 3 - Menggunakan switch

const byte PIN_MERAH = 2;
const byte PIN_HIJAU = 3;
const byte PIN_KUNING = 4;

void setup() 
{
  pinMode(PIN_MERAH, OUTPUT);
  pinMode(PIN_HIJAU, OUTPUT);
  pinMode(PIN_KUNING, OUTPUT);

  // Pembangkit bilangan acak
  //   diisi dengan nilai acak
  randomSeed(analogRead(0));

  // Bangkitkan bilangan acak antara 0 dan 2
  int bilangan = random(3);  

  // Kontrol LED yang akan dinyalakan
  switch (bilangan)
  {
  case 0:
    digitalWrite(PIN_MERAH, HIGH);
    break;
  case 1:
    digitalWrite(PIN_HIJAU, HIGH);
    break;
  case 2:
    digitalWrite(PIN_KUNING, HIGH);
    break;
  }
}

void loop() 
{
  
}

