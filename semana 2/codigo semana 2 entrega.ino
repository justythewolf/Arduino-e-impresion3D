// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(4, HIGH);
  delay(10000); 
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  delay(2000); 
  digitalWrite(2, LOW);
  digitalWrite(7, HIGH);
  delay(20000);
  digitalWrite(7, LOW);
}