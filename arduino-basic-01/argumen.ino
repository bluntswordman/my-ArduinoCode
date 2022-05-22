// Contoh pendefinisian fungsi
//   yang mengandung argumen

void setup()
{
  Serial.begin(9600);
  
  Serial.println(ulangSimbol('*', 5));
  Serial.println(ulangSimbol('=', 10));
}

void loop()
{
}

String ulangSimbol(char simbol, int jumlah)
{
  String hasil = "";
 
  for (int j = 0; j < jumlah; j++)
    hasil = hasil + simbol;
   
  return hasil;  
}

