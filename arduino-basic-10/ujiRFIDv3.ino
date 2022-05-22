// Contoh untuk mendapatkan nomor ID tag
//   dalam bentuk heksadesimal dan unsigned long

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

        // Peroleh ID tag
        String idHeksa;
        for (int j = 0; j < 12; j++)
        {
          String st = dataTag.substring(2 * j + 2, 2 * j + 4); 
          idHeksa = idHeksa + char(strtoul(st.c_str(), NULL, 16));
        }

        Serial.print("ID (Hex): ");
        Serial.println(idHeksa);

        // Untuk mendapatkan nilai dalam long
        //   abaikan dua digit pertama dan terakhir
        idHeksa = idHeksa.substring(2, 10);
        long bil = strtol(idHeksa.c_str(), NULL, 16);

        Serial.print("ID (Des): ");
        Serial.println(bil);
      }
       
      // Untuk mencegah pembacaan yang berulang
      dataSebelum = dataTag;
      dataTag = "";
    }
  }
}

