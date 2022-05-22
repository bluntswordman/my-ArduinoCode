// Contoh pengujian modul RDM6300

void setup()
{
  Serial.begin(9600);  
  Serial3.begin(9600);

  Serial.println("Silakan mendekatkan tag RFID");
}
 
void loop()
{
  if (Serial3.available() > 0) 
  {
     int data = Serial3.read();
     
     Serial.print(data, HEX);
     Serial.print(" ");
  }
}

