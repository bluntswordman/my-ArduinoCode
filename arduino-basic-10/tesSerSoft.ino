// Contoh untuk membuat port serial
//   secara software

#include <SoftwareSerial.h>

SoftwareSerial rfid(10, 11); // RX dan TX Arduino

String dataTag = "";
String dataSebelum = "";

void setup()
{
  rfid.begin(9600);   
  Serial.begin(9600);  

  Serial.println("Silakan mendekatkan tag RFID");
}
 
void loop()
{
  if (rfid.available() > 0) 
  {
     int data = rfid.read();
     
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

