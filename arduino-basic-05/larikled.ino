// Contoh penggunaan for 
//    untuk menghidupkan LED dari ujung kiri
//    ke kanan

int pin[] = {12, 11, 9, 8, 6, 5, 4, 3};

void setup() 
{ 
  Serial.begin(9600);
  
  for (int indeks = 0; indeks < 8; indeks++) 
  {
    pinMode(pin[indeks], OUTPUT);
    digitalWrite(pin[indeks], LOW); 
  }
}

void loop() 
{
  for (int indeks = 0; indeks < 8; indeks++) 
  {
    digitalWrite(pin[indeks], HIGH);
    delay(500);
    digitalWrite(pin[indeks], LOW); 
  }
}

