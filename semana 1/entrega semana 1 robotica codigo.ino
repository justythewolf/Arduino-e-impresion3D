// C++ code
//
int counter;

void setup()
{
  pinMode(7, OUTPUT);
}

void loop()
{
  for (counter = 0; counter < 10000; ++counter) {
    digitalWrite(7, HIGH);
    delay(10000); // Wait for 10000 millisecond(s)
    digitalWrite(7, LOW);
    delay(20000); // Wait for 20000 millisecond(s)
  }
}