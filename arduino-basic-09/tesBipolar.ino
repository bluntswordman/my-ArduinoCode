// Contoh untuk menguji motor stepper NEMA 17 dan
//   kompatibelnya

#include <Stepper.h>

const byte FULL_STEPS = 200;  

// Inisialisasi motor stepper
Stepper bipolarStepper(FULL_STEPS, 2, 3, 4, 5);            

void setup() 
{
  bipolarStepper.setSpeed(60);
}

void loop() 
{
  // Putar setengah putaran pada satu arah
  bipolarStepper.step(FULL_STEPS / 2);
  delay(2000);
  
  // Putar setengah putaran pada arah berlawanan
  bipolarStepper.step(-FULL_STEPS / 2);
  delay(2000);
}

