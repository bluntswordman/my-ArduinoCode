// Contoh untuk menguji HC06
//   HC06 dihubungkan ke pin 18 dan 19
//   untuk menggunakan objek Serial1

void setup() 
{
  // Atur laju bit komunikasi Bluetooth
  Serial1.begin(9600);
}

void loop() 
{
  Serial1.println("Pesan dari HC06..");

  delay(1000); 
}

