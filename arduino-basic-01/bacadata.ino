// Contoh pembacaan data yang berasal dari
//   Serial Monitor menggunakan available()
//   dan read()

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Deklarasi string
  String teks = "";
  
  while (Serial.available() > 0)
  {
    // Berarti ada data yang belum dibaca
   
    // 1. Baca sebuah karakter
    char karakter = Serial.read();
   
    // Tambahkan karakter ke string teks
    teks = teks + karakter;
    
    // Tunda sebentar
    delay(10);
  }
  
  // Periksa isi teks kosong atau tidak
  if (teks.length() == 0)
    return;
    
  // Teks berisi string, maka...
  Serial.print("Teks: ");
  Serial.println(teks);  
}

