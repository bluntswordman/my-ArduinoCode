// Contoh penggunaan ++ dan --

void setup() 
{
  Serial.begin(9600);

  int bilangan;
  bilangan = 1;
  Serial.println(bilangan);

  bilangan++;
  Serial.println(bilangan);

  bilangan++;
  Serial.println(bilangan);

  bilangan--;  // Turunkan sebesar 1
  Serial.println(bilangan);
}

void loop() 
{
  
}
