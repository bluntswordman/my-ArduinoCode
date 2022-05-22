// Contoh pengontrolan solenoid sebagai kunci
//   melalui password

#include <Keypad.h>

const byte PIN_RELAI = 11;

char tombol[4][4] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char* kunci = "AB1234"; // Password

byte pinBaris[] = {9, 8, 7, 6};
byte pinKolom[] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(tombol), 
                pinBaris, pinKolom, 4, 4);

int posisi = 0;
char strPassword[9];

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_RELAI, OUTPUT);
  digitalWrite(PIN_RELAI, LOW);
}

void loop() 
{
  char kode = keypad.getKey();
  if (kode == NO_KEY)
    return;

  if (kode == '*') 
  {
    Serial.println("Awal pemasukan password");
    posisi = 0;
    return;
  }
  else if (kode == '#')
  {
    Serial.println("Akhir pemasukan password");
    Serial.print("Password dimasukkan: ");
    Serial.println(strPassword);
    if (strcmp(strPassword, kunci) == 0)
    {
      digitalWrite(PIN_RELAI, HIGH);
      delay(4000);
    }

    strcpy(strPassword, "");
    posisi = 0;
    digitalWrite(PIN_RELAI, LOW);
  }
  else
  {
    if (posisi == 9)
      return;

    strPassword[posisi] = kode;
    posisi++;  
    strPassword[posisi] = 0;
  }  
}

