// Contoh pemakaian keypad TTP229

const byte PIN_SCL = 21;
const byte PIN_SDO = 20;

void setup() 
{
  Serial.begin(9600);
 
  pinMode(PIN_SCL, OUTPUT);  
  pinMode(PIN_SDO, INPUT); 
  Serial.println("Silakan menekan tombol...");
}

void loop() 
{
  byte tombol = bacaKeypad();
  if (tombol != 0)
    Serial.println(tombol); 
 
  delay(200);
  
}

byte bacaKeypad(void) 
{
  byte tombolDitekan = 0;
  for (int tombol = 1; tombol <= 16; tombol++) 
  {
   digitalWrite(PIN_SCL, LOW); 
   if (digitalRead(PIN_SDO) == LOW)
     tombolDitekan = tombol; 
     
   digitalWrite(PIN_SCL, HIGH);
 } 
  
 return tombolDitekan; 
}

