// Contoh pengaturan intensitas LED
//   pada 3 LED secara acak

const byte PIN_LED_A = 44;
const byte PIN_LED_B = 45;
const byte PIN_LED_C = 46;

const byte ANGKA_DASAR = 40;
const byte ANGKA_ACAK = 256 - ANGKA_DASAR;

void setup() 
{
  pinMode(PIN_LED_A, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_LED_C, OUTPUT);
}

void loop() 
{
  byte acakA = random(ANGKA_ACAK);
  byte acakB = random(ANGKA_ACAK);
  byte acakC = random(ANGKA_ACAK);
  
  analogWrite(PIN_LED_A, ANGKA_DASAR + acakA);
  analogWrite(PIN_LED_B, ANGKA_DASAR + acakB);
  analogWrite(PIN_LED_C, ANGKA_DASAR + acakC);
  delay(30);
}

