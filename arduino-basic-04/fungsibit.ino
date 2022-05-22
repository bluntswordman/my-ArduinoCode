// Contoh pemakaian fungsi-fungsi
//   yang berhubungan dengan operasi bit

void setup() 
{
  Serial.begin(9600);

  byte bilangan = B10110101;
  Serial.println("Data semula:");
  Serial.println(bilangan, BIN);

  Serial.print("Bit posisi 2: ");
  Serial.println(bitRead(bilangan, 2));

  bitClear(bilangan, 2);
  Serial.println("Setelah bit posisi 2 dikosongkan");
  Serial.println(bilangan, BIN);

  Serial.print("Bit posisi 2: ");
  Serial.println(bitRead(bilangan, 2));

  bitSet(bilangan, 2);
  Serial.println("Setelah bit posisi 2 dibuat menjadi 1");
  Serial.println(bilangan, BIN);
  Serial.print("Bit posisi 2: ");
  Serial.println(bitRead(bilangan, 2));
}

void loop() 
{
  
}
