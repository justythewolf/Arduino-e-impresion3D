// C++ code
//
int verde = 4;
int rojo = 3;
int pir = 2;
int buzzer = 5;
int val;
void setup()
{
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(pir, INPUT);
}

void loop()
{
	val = digitalRead(pir); 
      if (val > 0) {
        tone(buzzer, 500, 50);
      	digitalWrite(verde, HIGH);
        digitalWrite(rojo, LOW);
        delay(1000);
}    }
  else {
    	digitalWrite(rojo, HIGH);
    	digitalWrite(verde, LOW);
  } 
