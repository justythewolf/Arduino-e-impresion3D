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

void loop(){
  val=analogRead(POTENCIOMETRO);
  Serial.println(val);
  if  (val>500){
  	digitalWrite(LED,HIGH);
    digitalWrite(LED2, LOW);
    }
   else {
   	digitalWrite(LED2,HIGH);
    digitalWrite(LED, LOW);
    }
}

