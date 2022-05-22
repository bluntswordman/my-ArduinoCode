// Contoh komunikasi dua arah
//   antara Arduino dan HC06

void setup() 
{
  Serial1.begin(9600);
  Serial1.println("Ketik 0, 1, atau 2");
}

void loop() 
{
  char dataBt; // Data dari Bluetooth
  
  if (Serial1.available()) 
  {
    dataBt = Serial1.read();
    if (dataBt == '0' || dataBt == '1' || dataBt == '2') 
    {   
      Serial1.print("Anda baru saja menekan tombol ");
      Serial1.println(dataBt);
    }
  }
}

