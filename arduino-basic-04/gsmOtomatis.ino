// Contoh untuk mengirimkan SMS
//   dengan memastikan modul GSM 
//   dalam keadaan aktif

const byte PIN_GSM_ON = 8;

void setup()
{
  Serial.begin(9600);  // Serial Monitor
  Serial2.begin(9600); // Modul GSM    
  delay(100);

  aktifkanGSM();
  
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
  Serial2.println("AT+CMGS=\"+62857134xxxxx\"\r"); 
  delay(1000);
  Serial2.println(pesan);
  delay(100);

  // Akhiri dengan Ctrl+Z
  Serial2.println((char)26);
  delay(1000);
}

 

void aktifkanGSM() 
{
  Serial.println("Mengaktifkan PWR_KEY...");
  
  pinMode(PIN_GSM_ON, OUTPUT);
 
  // Aktifkan modul GSM
  digitalWrite(PIN_GSM_ON, HIGH);
  delay(1500);
  digitalWrite(PIN_GSM_ON, LOW);
  delay(2000);
  digitalWrite(PIN_GSM_ON, HIGH);
  delay(3000);
}

