// Contoh pembuatan LED berkedip
//   melalui pengaturan register interupsi

const byte PIN_LED = 12;

void setup()
{
  pinMode(PIN_LED,OUTPUT);

  // inisialisasi Timer1
  cli(); // Matikan interupsi 

  // Atur semua bit pada TCR1A dan TCR1B menjadi 0
  TCCR1A = 0;
  TCCR1B = 0;

  // Atur nilai pada compare match register
  //   agar timer bekerja dengan frekuensi 1Hz
  OCR1A = 15624;

  // Aktifkan mode CTC
  TCCR1B |= (1 << WGM12);

  // Set CS10 and CS12 bits for 1024 prescaler:
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);

  // enable timer compare interrupt:
  TIMSK1 |= (1 << OCIE1A);
  
  sei();// enable global interrupts
}

void loop()
{
  
}

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
}


