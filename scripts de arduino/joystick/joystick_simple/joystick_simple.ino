#include <LiquidCrystal.h>
LiquidCrystal LCD = LiquidCrystal(3, 13, 4, 5, 6, 7); 
const byte EJE_X = A0;
const byte EJE_Y = A1;
int boton = 2;
int rojo = 8;
int verde = 9;
int amarillo = 10;
int verde2 = 11;
void setup() {
  LCD.begin(16, 2);
  pinMode(boton, INPUT_PULLUP);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(amarillo, OUTPUT);
}

void loop() {
  int valorX = analogRead(EJE_X);
  int valorY = analogRead(EJE_Y);
  int botonPulsado = digitalRead(boton);
  
  if (valorX < 450) {
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo, LOW);
  }
  else if (valorX > 550) {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo, LOW);
  } 
  else {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo, LOW);
  }
  if (valorY < 450) {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo, HIGH);
  }
  else if (valorY > 550) {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(verde2, HIGH);
    digitalWrite(amarillo, LOW);
  }
  else {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo, LOW);
  }
  if (botonPulsado == 0) {
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(verde2, HIGH);
    digitalWrite(amarillo, HIGH);
  }
  LCD.setCursor(0, 0);
  LCD.print(valorX);
  LCD.setCursor(0, 1);
  LCD.print(valorY);
  LCD.clear();
  
  
}
