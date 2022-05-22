// Contoh penggunaan while

void setup() 
{
  Serial.begin(9600);
  
  int pin = 2;

  while (pin <= 13)
  {
    Serial.print("Pin #");
    Serial.println(pin);

    pin++; // Naikkan nilai pin sebesar 1  
  };

  Serial.println("*****");
}

void loop() 
{
}

