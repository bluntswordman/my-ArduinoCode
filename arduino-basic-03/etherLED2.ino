// Contoh untuk mengendalikan LED
//   melalui browser
//   Versi: POST

#include "UIPEthernet.h"

const byte PIN_LED = 2;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Inisialisasi web server
EthernetServer server(80);

bool keadaanLed = false;
String permintaanKlien;
String dataPost;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, keadaanLed);
  
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
    while (klien.connected()) {
      if (klien.available()) {
        char c = klien.read();
        
        permintaanKlien += c;
        
        if (c == '\n' && barisSekarangKosong) 
        {
          // Baca data POST dahulu
          dataPost = "";
          char karPost;
          while(klien.available()) 
          {
             karPost = klien.read();
             dataPost += karPost;
          }
          
          Serial.println("\nData POST:");
          Serial.println(dataPost);
          Serial.println("-------- Akhir data post");

          // Kirim tanggapan HTTP
          klien.println("HTTP/1.1 200 OK");
          klien.println("Content-Type: text/html");
          klien.println("Connection: close");   
          klien.println(); 

          // Kirim halaman web
          klien.println("<!DOCTYPE HTML>");
          klien.println("<html>");
          klien.println("<head>");
          klien.println("<title>Pengendalian LED</title>");
          klien.println("</head>");
          klien.println("<body>");
          
          klien.println("<form method=\"post\">");
          
          prosesPermintaan();
  
          if (keadaanLed) 
          {
            klien.println("<input type=\"submit\"");
            klien.println(
               "       name=\"tombol\" value=\"Matikan LED\">");
          }
          else 
          {
            klien.println("<input type=\"submit\"");
            klien.println(
              "       name=\"tombol\" value=\"Hidupkan LED\">");
          }  
          
          klien.println("</form>");
          
          klien.println("</body>");
          klien.println("</html>");
          
          // Tampilkan permintaanKlien dan kemudian kosongkan
          Serial.println(permintaanKlien);
          permintaanKlien = "";
          
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

void prosesPermintaan() 
{
  // Tentukan keadaanLed sekarang
  if (dataPost.
      indexOf("tombol=Hidupkan+LED") > -1) 
  {
     keadaanLed = true;
     digitalWrite(PIN_LED, HIGH);
  }
  else
    if (dataPost.
        indexOf("tombol=Matikan+LED") > -1 ) 
    {
      keadaanLed = false;
      digitalWrite(PIN_LED, LOW);
    }
 }

