// C++ code
//
const int buzzer = 2;
const int rojo = 4;
const int verde = 7;
int tono = 200;
void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);	
}
void alarma() {
  digitalWrite(verde, LOW);
  digitalWrite(rojo, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(rojo, LOW);
  digitalWrite(buzzer, LOW);
  delay(500);
}
long distancia(int trigger, int echo){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger,HIGH);
  //delay(1); //1 milisegundo
  digitalWrite(trigger,LOW);
  return pulseIn(echo, HIGH);
}
void loop()
{
    int cm = distancia(12,13) / 58.2;
    Serial.println(cm);
  if (cm < 200) {
   alarma(); 
  } else {
   		digitalWrite(verde, HIGH);
  }
}


/*
cabe aclarar que deje una resistencia de lado ya que no tenia
lugar en ninguna parte del codigo 
*/