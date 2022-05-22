// Contoh penggunaan break

void setup() 
{
  Serial.begin(9600);
  
  for (int pin = 2; pin <= 12; pin++) 
  {
     if (pin == 8)
       break;  

     Serial.println(pin);  
  };

  Serial.println("*****");
}

void loop() 
{
}

