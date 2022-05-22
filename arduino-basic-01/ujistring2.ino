// Contoh pengunaan sejumlah fungsi string
//   pada string yang bertipe String

void setup()
{
  Serial.begin(9600);

  // Deklarasi string dan inisialisasi
  String namaKomponen = "Resistor";

  // Tampilkan string
  Serial.print("Isi semula: ");
  Serial.println(namaKomponen);
  
  // Peroleh jumlah karakter
  Serial.print("Jumlah karakter: ");
  Serial.println(namaKomponen.length());

  // Tambahkan 2K
  namaKomponen = namaKomponen + " 2K";
  
  // Tampilkan string
  Serial.print("Isi sekarang: ");
  Serial.println(namaKomponen);
  
  // Konversi ke kapital
  namaKomponen.toUpperCase(); 
  
  // Tampilkan string
  Serial.print("Setelah konversi: ");
  Serial.println(namaKomponen);  
}

void loop()
{
}

