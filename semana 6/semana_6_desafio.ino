#include <LiquidCrystal.h>
LiquidCrystal miLCD(12, 11, 5, 4, 3, 2);
      /*Los valores del array están expresados en decimal*/
//byte smiley[8] = {0,17,0,0,17,14,0};
const int verde = 7;
const int rojo = 6;
const int tmp = A0;
const int buzzer = 8;
float grados;
void setup(){
    //los parámetros de la función son el id del carácter (un entero entre 0 y 7) y el array de valores que corresponden al dibujo
	//miLCD.createChar(0, smiley);
  	pinMode(verde, OUTPUT);
	pinMode(rojo, OUTPUT);
  	pinMode(buzzer, OUTPUT);
  	pinMode(tmp, INPUT);
    //La pantalla tiene 16 columnas y 2 filas
    miLCD.begin(16, 2);

    //indicamos el id de carácter donde está guardado el dibujo y el tipo de dato de ese id, que es byte
    //miLCD.write(byte(0));
    }


// la toma de temperatura se hace cada 2 sec
void loop(){
  grados = analogRead(tmp);
  grados = (grados * 0.4887586) - 50;
  miLCD.print(grados);
  miLCD.print(" grados");
  while (grados <= 37) {
    tone(buzzer, 200, 200);
    digitalWrite(verde, HIGH);
    digitalWrite(buzzer, HIGH);
    miLCD.setCursor(0, 1);
    miLCD.print("puede entrar");
    delay(200);
    digitalWrite(buzzer, LOW);
    digitalWrite(verde, LOW);
    break;
  } if (grados > 37) {
    for (int i = 0; i < 5; i++) {
      tone(buzzer, 400, 200);
      digitalWrite(rojo, HIGH);
      digitalWrite(buzzer, HIGH);
      miLCD.setCursor(0, 1);
      miLCD.print("no puede entrar");
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }
  }
  delay(2000);
  miLCD.clear();
}
