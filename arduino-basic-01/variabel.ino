void setup() 
{
  Serial.begin(9600);

  // Deklarasi variabel
  float tegangan;

  // Pemberian nilai
  tegangan = 5;

  Serial.print("Tegangan: ");
  Serial.print(tegangan);
  Serial.println(" volt");

  // Pengubahan isi variabel
  
  tegangan = 0;

  Serial.print("Tegangan: ");
  Serial.print(tegangan);
  Serial.println(" volt");
}

void loop() 
{
  
}
