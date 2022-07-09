#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD = LiquidCrystal(13, 12, 7, 6, 5, 4);
const int tira1 = 2;
const int tira2 = 3;
const int rojo = 17;
const byte tomaLuz = A0;
const byte sensTMP = A1;
const int boton = 8;
Servo servo1;
Servo servo2;
const byte sensForce = A2;
const int buzzer = 11;
const byte PIR = A4;
float force;
float tmp;
float luz;
void setup()
{
  Serial.begin(9600);
  pinMode(tira1, OUTPUT);
  pinMode(tira2, OUTPUT);
  pinMode(tomaLuz, INPUT);
  pinMode(boton, INPUT);
  pinMode(sensForce, INPUT);
  LCD.begin(16, 2);
  pinMode(sensTMP, INPUT);
  servo1.attach(9);
  servo2.attach(10);
}
//sistema de luces para que el modulo se identifique en la falta de luz
void sysLuces() {
  luz = analogRead(tomaLuz);
  Serial.println(luz);
	if (luz < 500) {
    digitalWrite(tira1, HIGH);
    digitalWrite(tira2, HIGH);
    
  } else {
    digitalWrite(tira1, LOW);
    digitalWrite(tira2, LOW);
  } 
}
//sistema del termometro
void termometro() {
  float tmp = analogRead(sensTMP);
  float vol = 5.0 / 1024 * tmp;
  float grados = vol * 100 - 50;
  
  LCD.print(grados);
  LCD.print(" grados");
  if (grados <= 37) {
    LCD.setCursor(0, 1);
    
    LCD.println("pase el siguiente");
    LCD.autoscroll();
  } else if (grados > 37) {
    LCD.setCursor(0, 1);
    LCD.println("no pasar, paciente enfermo");
  }
  delay(2000);
  LCD.clear();
  
}
//sistema de subida de camillas de la calle al modulo
void subida() {
  int press = digitalRead(boton);
    Serial.println(press);
    if (press == 1) {
      servo1.write(90);
      servo2.write(90);
    } else {
      servo1.write(0);
      servo2.write(0);
    }
}
//sistema de alarma de presion de la puerta
void presion() {
    force = analogRead(sensForce);
    Serial.println(force);
    
    if (force < 700) {
      	tone(buzzer, 200, 200);
        digitalWrite(rojo, HIGH);
        digitalWrite(rojo, LOW);
      } else {
        digitalWrite(rojo, LOW);
      }
    
}
//las 4 funciones de este modulo
  void loop() {
    sysLuces();
    subida();
    presion();
    termometro();
   
  }
