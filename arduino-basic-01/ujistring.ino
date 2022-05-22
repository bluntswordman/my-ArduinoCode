// Contoh operasi string
//   pada string yang berakhiran nol

void setup()
{
  Serial.begin(9600);

  // Deklarasi string dan inisialisasi
  char namaKomponen[20] = "Resistor";

  // Tampilkan string
  Serial.print("Isi semula: ");
  Serial.println(namaKomponen);
  
  // Peroleh jumlah karakter
  Serial.print("Jumlah karakter: ");
  Serial.println(strlen(namaKomponen));

  // Tambahkan 2K
  strcat(namaKomponen, " 2K");
  
  // Tampilkan string
  Serial.print("Isi sekarang: ");
  Serial.println(namaKomponen);
  
  // Konversi ke kapital
  strupr(namaKomponen);

  // Tampilkan string
  Serial.print("Setelah konversi: ");
  Serial.println(namaKomponen);  
}

void loop()
{
}

