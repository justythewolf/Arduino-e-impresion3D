#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal LCD = LiquidCrystal(13, 12, 7, 6, 5, 4);
const byte sensAgua = A0;
const int buzzer = 2;
Servo servo1;


void setup() {
  Serial.begin(9600);
  LCD.begin(16, 2);
  pinMode(sensAgua, INPUT);
  servo1.attach(8);
}

void loop() {
  int agua = analogRead(sensAgua);
  LCD.print("humedad: ");
  LCD.print(analogRead(sensAgua));
  if (agua < 200) {
    LCD.setCursor(0, 1);
    LCD.write("esta seco");
    servo1.write(90);
  } else {
    tone(buzzer, 200, 200);
    LCD.setCursor(0, 1);
    LCD.write("esta mojado");
    servo1.write(180);
  }
  
  
  delay(3000);
  LCD.clear();
  LCD.home();
}
