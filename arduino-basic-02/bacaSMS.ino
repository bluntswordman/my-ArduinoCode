// Contoh untuk membaca SMS

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
      Serial.println(tanggapan);
  }
}
