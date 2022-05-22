// Contoh untuk menguji keypad 4 x 3

#include "Keypad.h"

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

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  char kode = keypad.getKey();
  if (kode != NO_KEY)
    Serial.println(kode);
}


