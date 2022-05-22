// Contoh untuk menguji keypad 4 x 4

#include "Keypad.h"

char petaTombol[4][4] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinBaris[] = {9, 8, 7, 6};
byte pinKolom[] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(petaTombol), 
                pinBaris, pinKolom, 4, 4);

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


