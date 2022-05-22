// Contoh penggunaan keypad 4 x 3
//   untuk mengontrol 2 LED

#include "Keypad.h"

const byte PIN_LED1 = 12;
const byte PIN_LED2 = 11;

char petaTombol[4][3] = 
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pinBaris[] = {8, 7, 6, 5};
byte pinKolom[] = {4, 3, 2};
Keypad keypad = Keypad(makeKeymap(petaTombol), 
                pinBaris, pinKolom, 4, 3);

byte keadaanLED1 = LOW;
byte keadaanLED2 = LOW;

void setup() 
{
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

void loop() 
{
  char kode = keypad.getKey();
  if (kode != NO_KEY)
  {
    switch(kode)
    {
      case '*':
        digitalWrite(PIN_LED1, HIGH);
        digitalWrite(PIN_LED2, HIGH);
        keadaanLED1 = HIGH;
        keadaanLED2 = HIGH;
        break;
      case '#':
        digitalWrite(PIN_LED1, LOW);
        digitalWrite(PIN_LED2, LOW);
        keadaanLED1 = LOW;
        keadaanLED2 = LOW;
        break;
      case '1':
        keadaanLED1 = !keadaanLED1;
        digitalWrite(PIN_LED1, keadaanLED1);
        break;
      case '2':
        keadaanLED2 = !keadaanLED2;
        digitalWrite(PIN_LED2, keadaanLED2);
        break;        
    }
  }
}


