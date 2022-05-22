// Contoh pengontrolan LED via Bluetooth

const byte PIN_LED = 8;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);
  
  Serial1.begin(9600);
  Serial1.println("Tekan 1 = untuk menghidupkan LED");
  Serial1.println("      0 = untuk mematikan LED");
}

void loop() 
{
  char dataBt; // Data dari Bluetooth
  
  if (Serial1.available()) 
  {
    dataBt = Serial1.read();
    if (dataBt == '0') 
    {   
      digitalWrite(PIN_LED, LOW);
      Serial1.println("LED dimatikan...");
    }
    else if (dataBt == '1') 
    {
      digitalWrite(PIN_LED, HIGH);
      Serial1.println("LED dihidupkan...");
    }
  }
}

