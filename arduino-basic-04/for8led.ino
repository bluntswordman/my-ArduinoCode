// Contoh penggunaan for 
//    untuk mengendalikan 8 LED

void setup() 
{ 
  Serial.begin(9600);
  
  for (int pin = 12; pin >= 5; pin--) 
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); 
  }
}

void loop() 
{
  for (int pin = 12; pin >= 5; pin--) 
  {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW); 
  }
}

