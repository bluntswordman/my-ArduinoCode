// Contoh sketsa yang memungkinkan 
//   untuk memantau suhu via web browser

#include "UIPEthernet.h"

const int PIN_SUHU = A0;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Inisialisasi web server
EthernetServer server(80);

void setup() 
{
  Serial.begin(9600);
  
  Ethernet.begin(mac);
  server.begin();
  
  Serial.print("IP Server: ");
  Serial.println(Ethernet.localIP());
}

void loop() 
{
  // Periksa permintaan dari klien
  EthernetClient klien = server.available();
  if (klien) 
  {
    Serial.println("Permintaan baru...");
  
    boolean barisSekarangKosong = true;
    while (klien.connected()) 
    {
      if (klien.available()) 
      {
        char c = klien.read();
        Serial.write(c);
        if (c == '\n' && barisSekarangKosong) 
        {
          // Kirim tanggapan HTTP
          klien.println("HTTP/1.1 200 OK");
          klien.println("Content-Type: text/html");
          klien.println("Connection: close");  
          klien.println("Refresh: 5");  
          klien.println();

          // Kirim halaman web
          klien.println("<!DOCTYPE HTML>");
          klien.println("<html>");
          klien.println("<head>");
          klien.println(
            "<title>Pemantauan Suhu Ruangan</title>");
          klien.println("</head>");
          klien.println("<body>");
          
          // Baca LM35DZ
          float celsius = analogRead(PIN_SUHU) * 0.48876;
          char strSementara[7];
          dtostrf(celsius, 6, 2, strSementara);
          
          klien.print("Temperatur: ");
          klien.print(strSementara);
          klien.println("&deg;C<br>");

          klien.println("</body>");
          klien.println("</html>");
          break;
        }
        
        if (c == '\n') 
        {
          // Baris sekarang kosong
          barisSekarangKosong = true;
        } 
        else 
          if (c != '\r') 
          {
            // Ada karakter baru
            barisSekarangKosong = false;
          }
      }
    }
    
    // Beri kesempatan kepada browser
    //   untuk memperoleh data
    delay(10);

    // Akhiri koneksi
    klien.stop();
    Serial.println("Klien terputus...");
  }
}

