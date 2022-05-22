// Contoh penggunaan && untuk
//   menguji suatu karakter
//   termasuk huruf kapital atau bukan

void setup() 
{
  Serial.begin(9600);
  
  char kar;

  kar = 'M';
  Serial.print(kar);
  Serial.print(" -> ");
  Serial.println(kar >= 'A' && kar <= 'Z');

  kar = 'm';
  Serial.print(kar);
  Serial.print(" -> ");
  Serial.println(kar >= 'A' && kar <= 'Z');
}

void loop() 
{
  
}
