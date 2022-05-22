// Contoh penggunaan potensiometer digital
//   MCP41010

#include <SPI.h>

const byte PIN_SS = 53; 
 
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_SS, OUTPUT); 
  
  SPI.begin(); 
}
 
void loop()
{
  for (byte nilai = 0; nilai < 256; nilai++)
  { 
    aturNilai(nilai);
    delay(200);

    // Baca data
    float tegangan = 5.0 * analogRead(A0) / 1023.0;

    Serial.print(nilai);
    Serial.print(" -> ");
    Serial.print(tegangan, 3);
    Serial.println(" volt");
  }  
}

void aturNilai(byte nilai)
{
  digitalWrite(PIN_SS, LOW);
  SPI.transfer(0x11); 
  SPI.transfer(nilai); 
  digitalWrite(PIN_SS, HIGH);
}

