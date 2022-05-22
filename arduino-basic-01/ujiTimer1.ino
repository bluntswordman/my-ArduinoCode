// Contoh penggunaan TimerOne
//   untuk membuat LED berkedip
 
#include "TimerOne.h"

const byte PIN_LED = 12;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  Timer1.initialize(1000000);                        
  Timer1.attachInterrupt(kedip);  
}
 
void kedip()
{
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
}
 
void loop()
{
  
}
