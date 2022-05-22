// Contoh untuk membaca SMS
//   dengan mendapatkan nomor telepon pengirim
//   dan pesan SMS secara terpisah

struct DataSMS
{
  String nomorTelepon;
  String pesanSMS;
};

void setup()
{
  Serial.begin(9600);
  
  Serial2.begin(9600);  
  delay(2000); 
    
  Serial2.println("AT+CMGF=1"); 
  delay(200);

  Serial.println("Siap menerima SMS!");
}
 
void loop() 
{
  Serial2.println("AT+CMGL=\"REC UNREAD\"");
  delay(200);
  
  if (Serial2.available() > 0)
  {
    String tanggapan = Serial2.readString();
    
    int pos = tanggapan.indexOf("+CMT:");
    if (pos > -1) 
    {
      struct DataSMS data = perolehDataSMS(tanggapan);

      Serial.println("SMS diterima...");
      Serial.print("Dari: ");
      Serial.println(data.nomorTelepon);
      Serial.println("Pesan: ");
      Serial.println(data.pesanSMS);
    }
  }
}

struct DataSMS perolehDataSMS(String data)
{
  struct DataSMS x;

  
  // Peroleh nomor telepon
  int pos1, pos2;

  pos1 = data.indexOf("+CMT:");
  
  pos1 = data.indexOf('"', pos1 + 6); 
  pos2 = data.indexOf('"', pos1 + 1);
  x.nomorTelepon = data.substring(pos1 + 1, pos2);
     
  // Peroleh pesan
  pos1 = data.indexOf('\n', pos2 + 1);
  pos2 = data.indexOf('\n', pos1 + 1);
  x.pesanSMS = data.substring(pos1 + 1, pos2);
  
  return x;
}

