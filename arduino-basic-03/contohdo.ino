// Contoh penggunaan do..while

void setup() 
{
  Serial.begin(9600);
  
  int pin = 2;

  do
  {
    Serial.print("Pin #");
    Serial.println(pin);

    pin++; // Naikkan nilai pin sebesar 1  
  } while (pin <= 13);

  Serial.println("*****");
}

void loop() 
{
}

