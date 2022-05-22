// Contoh operasi berbasis bit

void setup() 
{
  Serial.begin(9600);

  byte bilangan = 133;
  Serial.println("Data semula:");
  Serial.print(bilangan, BIN);
  Serial.print(" atau ");
  Serial.println(bilangan);

  bilangan = bilangan >> 1;
  Serial.println("Penggeseran 1 bit ke kanan:");
  Serial.print(bilangan, BIN);
  Serial.print(" atau ");
  Serial.println(bilangan);
  
  bilangan = bilangan << 1;
  Serial.println("Penggeseran 1 bit ke kiri:");
  Serial.print(bilangan, BIN);
  Serial.print(" atau ");
  Serial.println(bilangan);
  
  bilangan = bilangan >> 2;
  Serial.println("Penggeseran 2 bit ke kanan:");
  Serial.print(bilangan, BIN);  
  Serial.print(" atau ");
  Serial.println(bilangan);
}

void loop() 
{
  
}
