const int LED=7;
const int LED2=6;
const int POTENCIOMETRO=A0;
int val;

void setup(){

  pinMode(LED,OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(POTENCIOMETRO,INPUT);
  Serial.begin(9600);
}

void funcion() {
  val=analogRead(POTENCIOMETRO);
  Serial.println(val);
  if (val<500) { 
    while (val<500) {
      digitalWrite(LED,HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      break;
    }
  }
  else {
    while(val>500) {
      digitalWrite(LED2,HIGH);
      delay(200);
      digitalWrite(LED2, LOW);
      delay(200);
      break;
    }
  }
}


void loop() {
  funcion();
}