// Contoh pengujian operator relasional

void setup() 
{
  Serial.begin(9600);
  
  int a = 10;
  int b = 15;

  Serial.print("a > b -> ");
  Serial.println(a > b);

  Serial.print("b > a -> ");
  Serial.println(b > a);

  Serial.print("b != a -> ");
  Serial.println(b != a);

  Serial.print("b == a -> ");
  Serial.println(b == a);
}

void loop() 
{
  
}
