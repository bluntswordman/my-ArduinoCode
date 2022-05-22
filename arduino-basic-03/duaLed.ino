// Contoh untuk membuat dua LED berkedip
//   dengan interval berbeda

const byte LED_A = 6;
const byte LED_B = 5;
const int INTERVAL_A = 1000;
const int INTERVAL_B = 3000;

byte keadaan_LED_A = LOW;
byte keadaan_LED_B = LOW;
unsigned long waktuA, waktuB;

void setup () 
{  
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT); 

  waktuA = millis();
  waktuB = waktuA;
} 

void loop () 
{ 
  unsigned long kini = millis();
  
  // Tentukan LED A
  if (abs(kini - waktuA) > INTERVAL_A)  
  {
    waktuA = kini;
    keadaan_LED_A = not keadaan_LED_A;
    digitalWrite(LED_A, keadaan_LED_A);
  }

  // Tentukan LED B
  if (abs(kini - waktuB) > INTERVAL_B)  
  {
    waktuB = kini;
    keadaan_LED_B = not keadaan_LED_B;
    digitalWrite(LED_B, keadaan_LED_B);
  }
} 
