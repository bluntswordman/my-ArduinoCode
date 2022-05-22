// Contoh penghitungan pulsa
//   pada motor SPG30-300K

const byte CHANNEL_A = 2;
const byte CHANNEL_B = 3;

volatile int pulsa;
 
void setup() 
{
  Serial.begin(9600);

  pinMode(CHANNEL_A, INPUT);
  pinMode(CHANNEL_B, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(3), 
                  B_Berubah, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), 
                  A_Berubah, CHANGE);
}
 
void loop() 
{
  pulsa = 0;
  delay(1000);
  Serial.print("Jumlah pulsa : ");
  Serial.print(pulsa);  
  Serial.print(". RPM = ");
  Serial.println(pulsa * 60 / 900);
}

void A_Berubah() 
{
  if (digitalRead(CHANNEL_B) == LOW ) {
    if ( digitalRead(CHANNEL_A) == LOW ) {
      // A dan B dalam keadaan LOW
      pulsa--; // Berlawanan arah jarum jam
    } 
    else {
      // A berubah HIGH, B dalam keadaan LOW
      pulsa++; // Searah jarum jam
    }
  } 
  else 
    if ( digitalRead(CHANNEL_A) == LOW ) {
      // B LOW dan A HIGH
      pulsa++; // Berlawanan arah jarum jam
    } 
    else {
      // B berubah HIGH, A dalam keadaan HIGH
      pulsa--; // Searah jarum jam
    }
}

void B_Berubah(){
  if (digitalRead(CHANNEL_A) == LOW ) {
    if (digitalRead(CHANNEL_B) == LOW ) {
      // B berubah menjadi LOW, A dalam keadaan LOW 
      pulsa++; // Bergerak searah jam
    } 
    else {
      // B berubah HIGH, A dalam keadaan LOW
      pulsa--; // Berlawanan arah jarum jam
    }
  } 
  else {
    if (digitalRead(CHANNEL_B) == 0 ) {
      // B berubah LOW, A dalam keadaan HIGH
      pulsa--; // Berlawanan arah jarum jam
    } else {
      // B berubah HIGH, A dalam keadaan HIGH
      pulsa++; // Searah jarum jam
    }
  }
}

