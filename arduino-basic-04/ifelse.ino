// Contoh untuk menyalakan LED
//   secara acak
//   Versi 2

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
  if (bilangan == 0)
    digitalWrite(PIN_MERAH, HIGH);
  else
    if (bilangan == 1)
      digitalWrite(PIN_HIJAU, HIGH);
    else  
      if (bilangan == 2)
        digitalWrite(PIN_KUNING, HIGH);
}

void loop() 
{
  
}

