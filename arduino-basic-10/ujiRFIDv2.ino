// Contoh untuk mendapatkan nomor ID tag

String dataTag = "";
String dataSebelum = "";
 
void setup()
{
  Serial3.begin(9600);   
  Serial.begin(9600);  

  Serial.println("Silakan mendekatkan tag RFID");
}
 
void loop()
{
  if (Serial3.available() > 0) 
  {
     int data = Serial3.read();
     
     char teks[3]; 
     sprintf(teks, "%02X", data);
     dataTag = dataTag + teks;

     if (dataTag.length() == 28)
     {
       if (dataTag != dataSebelum)
       {
         Serial.print("Data Tag: ");
         Serial.println(dataTag);
       }

       dataSebelum = dataTag;
       dataTag = "";
     }  
  }
}

