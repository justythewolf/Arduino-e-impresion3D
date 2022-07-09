int counter;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (counter = 0; counter > 1000; counter++) {
    digitalWrite(7, HIGH);
    delay(10000); //miliseconds
    digitalWrite(7, LOW);
    delay(20000); //miliseconds 
  }
}
