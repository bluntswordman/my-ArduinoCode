// Contoh penggunaan potensiometor
//   untuk mengontrol motor servo

#include <Servo.h>

const byte PIN_SERVO  = 9;
const byte PIN_POTENSIO = A0;

// Buat objek
Servo motorServo;

void setup()
{
  // Motor servo dihubungkan ke pin servo
  motorServo.attach(PIN_SERVO);  
}

void loop()
{  
  // Baca data potensiometer
  int nilai = analogRead(PIN_POTENSIO);
  int sudutMotor = map(nilai, 0, 1023, 0, 180);
  motorServo.write(sudutMotor);
  delay(20);
}

