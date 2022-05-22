// Contoh untuk mengontrol LED
//   menggunakan SMS

const byte PIN_LED = 4;
const byte PIN_GSM_ON = 8;

struct DataSMS
{
  String nomorTelepon;
  String pesanSMS;
};

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  
  Serial.begin(9600);
  
  Serial2.begin(9600);  
  delay(2000); 
    
  Serial2.println("AT+CMGF=1"); 
  delay(200);

  aktifkanGSM();
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

      // Kontrol LED
      data.pesanSMS.trim(); // Hapus spasi putih
      
      if (data.pesanSMS.equalsIgnoreCase("LED ON"))
        digitalWrite(PIN_LED, HIGH);
      else
        if (data.pesanSMS.equalsIgnoreCase("LED OFF"))
          digitalWrite(PIN_LED, LOW);

      // Hapus semua SMS
      Serial2.println("AT+CMGD=1,4");
      delay(200); 
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


