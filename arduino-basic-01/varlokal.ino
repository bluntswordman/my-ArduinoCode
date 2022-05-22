// Contoh untuk menunjukkan
//   perbedaan variabel lokal dan global

int x = 10, y = 20; // Global

void setup()
{
  Serial.begin(9600);

  fungsiTes();
  
  Serial.println();
  
  Serial.println("Di setup()");
  Serial.print("  x global = ");
  Serial.println(x); 
   
  Serial.print("  y        = ");
  Serial.println(y);
}

void loop()
{
}

void fungsiTes()
{
   int x;  // lokal
  
   x = 34;
   
   Serial.println("Di fungsiTes()");
   Serial.print("  x lokal  = ");
   Serial.println(x); 
   
   Serial.print("  y        = ");
   Serial.println(y);
}

