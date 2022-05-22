// Contoh untuk menguji motor servo

#include <Servo.h>

const byte PIN_SERVO  = 9;

// Buat objek
Servo motorServo;

void setup()
{
  // Motor servo dihubungkan ke pin servo
  motorServo.attach(PIN_SERVO);  
}

void loop()
{  
  motorServo.write(0);
  delay(2000);
  
  motorServo.write(90);
  delay(2000);
  
  motorServo.write(135);
  delay(2000);
}

