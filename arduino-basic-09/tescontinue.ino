// Contoh penggunaan continue

void setup() 
{
  Serial.begin(9600);
  
  for (int pin = 2; pin <= 12; pin++) 
  {
     if (pin == 5)
       continue;  

     Serial.println(pin);  
  };

  Serial.println("*****");
}

void loop() 
{
}

