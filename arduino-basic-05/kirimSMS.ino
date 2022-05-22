// Contoh untuk mengirimkan SMS

void setup()
{
  Serial.begin(9600);  // Serial Monitor
  Serial2.begin(9600); // Modul GSM    
      
  delay(100);
  
  Serial.println("Siap untuk mengirim SMS!");
}

void loop()
{
  if (Serial.available() > 0)
  {
    String pesan = Serial.readString();
    Serial.println("Mencoba untuk mengirim SMS...");
    kirimPesan(pesan);
    Serial.println("Pengiriman berakhir...");
    Serial.println();
  }
}

void kirimPesan(String pesan)
{
  //Atur modul GSM pada mode teks
  Serial2.println("AT+CMGF=1");    
  delay(1000);  

  // Kirim SMS ke nomor berikut
  Serial2.println("AT+CMGS=\"+6285713438644\"\r"); 
  delay(1000);
  Serial2.println(pesan);
  delay(100);

  // Akhiri dengan Ctrl+Z
  Serial2.println((char)26);
  delay(1000);
}


