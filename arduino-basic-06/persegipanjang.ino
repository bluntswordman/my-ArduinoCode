// Contoh untuk menghitung
//   luas dan keliling persegi panjang
void setup() 
{
  Serial.begin(9600);

  float panjang = 20.5;
  float lebar = 10;

  float luas = panjang * lebar;
  float keliling = 2 * (panjang + lebar);
  
  Serial.print("Luas: ");
  Serial.println(luas);

  Serial.print("Keliling: ");
  Serial.println(keliling);
}

void loop() 
{
  
}
