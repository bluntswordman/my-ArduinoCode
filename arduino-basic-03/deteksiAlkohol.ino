// Pendeteksi alkohol

const int AMBANG = 450;
const int PIN_ANALOG = 0;
const int PIN_LED = 2;
const int PIN_ALARM = 3;

void setup() 
{
  pinMode(PIN_LED, OUTPUT);  

  Serial.begin(9600);
  Serial.println("Pendeteksi alkohol");
}

void loop() 
{
  int nilaiAnalog = analogRead(PIN_ANALOG);

  if (nilaiAnalog >= AMBANG)
  { 
    Serial.println("Alkohol terdeteksi...");
    delay(2000);
  }
}

