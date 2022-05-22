// Contoh pembacaan data yang berasal dari
//   Serial Monitor menggunakan available()
//   dan readString()

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Deklarasi string
  String teks = "";

  // Baca string jika tersedia
  if (Serial.available() > 0)
    teks = Serial.readString();
  
  // Periksa isi teks kosong atau tidak
  if (teks.length() == 0)
    return;
    
  // Teks berisi string, maka...
  Serial.print("Teks: ");
  Serial.println(teks);  
}

