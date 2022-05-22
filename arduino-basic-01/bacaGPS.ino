// Contoh untuk menguji modul GPS

void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() 
{ 
  if (Serial2.available()) 
  { 
    char karakter = Serial2.read();
    Serial.print(karakter); 
  }
}

