// Contoh pencacahan menggunakan
//   interupsi

const byte PIN_SENSOR = 2;

volatile int pencacah = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_SENSOR, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR), 
                  cacah, RISING); 
}

void loop() 
{

}

void cacah()
{
  pencacah++;
  Serial.print("Nilai pencacah = ");
  Serial.println(pencacah);
}

