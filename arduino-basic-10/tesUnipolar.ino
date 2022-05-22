// Contoh untuk menggerakkan motor stepper
//    satu putaran 
//    baik searah maupun berlawanan arah jam
//
//    Motor: 28BYJ-48 unipolar

#include <Stepper.h>

const byte STEP_SATU_PUTARAN = 2048;

// Buat objek motor stepper
Stepper motorStepper(STEP_SATU_PUTARAN, 8, 10, 9, 11);

void setup()
{
  // Atur kecepatan 
  motorStepper.setSpeed(4);   
}

void loop()
{
  // Putar pada satu arah
  motorStepper.step(STEP_SATU_PUTARAN);
  delay(1000);
  
  // Putar berlawanan arah sebelumnya
  motorStepper.step(-STEP_SATU_PUTARAN);
  delay(1000);
}

