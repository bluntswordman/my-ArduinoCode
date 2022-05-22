// Contoh untuk mengendalikan lengan robot
//   dengan dua derajat kebebasan

#include <Servo.h>

const byte PIN_SERVO_A = 9;
const byte PIN_SERVO_B = 10;

// Buat objek
Servo motorServoA;
Servo motorServoB;

void setup()
{
  Serial.begin(9600);
  
  // Motor servo dihubungkan ke pin servo
  motorServoA.attach(PIN_SERVO_A); 
  motorServoB.attach(PIN_SERVO_B);  
}

void loop()
{  
  int nilai_a0 = analogRead(A0);
  int nilai_a1 = analogRead(A1);

  Serial.print("A0: ");
  Serial.print(nilai_a0);
  Serial.print(", A1: ");
  Serial.println(nilai_a1);
  
  int sudutMotorA = map(nilai_a0, 0, 1023, 0, 180);
  int sudutMotorB = map(nilai_a1, 0, 1023, 0, 180);
  
  motorServoA.write(sudutMotorA);
  motorServoB.write(sudutMotorB);
  
  delay(200);
}

