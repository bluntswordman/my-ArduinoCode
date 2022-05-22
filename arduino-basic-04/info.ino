void setup() 
{
  Serial.begin(9600);
  Serial.println("Tulisan ini ditampilkan sekali");
}

void loop() 
{
  Serial.println("Ditulis per 2 detik");
  delay(2000);
}
