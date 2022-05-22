// Contoh untuk melihat efek interupsi

const byte PIN_TOMBOL = 2; 
 
void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_TOMBOL, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(PIN_TOMBOL), 
                  info, RISING); 
} 
 
void loop() 
{
  
} 
 
void info() 
{
  Serial.println("Tombol ditekan");
}
