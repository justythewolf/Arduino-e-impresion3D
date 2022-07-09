//RST           D9
//SDA(SS)      D10
//MOSI         D11
//MISO         D12
//SCK          D13

#include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>
#include <Servo.h>

#define STEPS 4096
#define NUMSTEPS 10000
const int RST_PIN = 9;            // Pin 9 para el reset del RC522
const int SS_PIN = 10;            // Pin 10 para el SS (SDA) del RC522
const int ledPin1 = 7;
const int ledPin2 = 6;
const byte buzzer = 2;
byte salida = 100;
byte ID[4];
byte Tarjeta[4] = {0x53, 0xA0, 0x88, 0x15};
byte llavero[4] =  {0xFC, 0x4D, 0xBB, 0x2B};
Servo servo; 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Crear instancia del MFRC522
Stepper stepper(STEPS,5,4,3,2);

void printArray(byte *buffer, byte bufferSize) {
   for (byte i = 0; i < bufferSize; i++) {
      Serial.print(buffer[i] < 0x10 ? " 0" : " ");
      Serial.print(buffer[i], HEX);
   }
}

void setup()
{
   Serial.begin(9600);      //Inicializa la velocidad de Serial
   SPI.begin();         //Función que inicializa SPI
   mfrc522.PCD_Init();     //Función  que inicializa RFID
   pinMode(ledPin1, OUTPUT);
   pinMode(ledPin2, OUTPUT);
   pinMode(buzzer, OUTPUT);
   servo.attach(3);
   stepper.setSpeed(5);
}

void loop()
{
   int angulo = map(RST_PIN, 0, 1023, 0, 180);
   // Detectar tarjeta
   if (mfrc522.PICC_IsNewCardPresent())
   {
      if (mfrc522.PICC_ReadCardSerial())
      {
         Serial.print(F("Card UID:"));
         //printArray(mfrc522.uid.uidByte, mfrc522.uid.size);
         byte *uidByte = mfrc522.uid.uidByte+mfrc522.uid.size;
         for (byte i = 0; i < mfrc522.uid.size; i++)
         {
          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(mfrc522.uid.uidByte[i], HEX);
          ID[i]=mfrc522.uid.uidByte[i];
          }
          Serial.println(*uidByte);
          if(compareArray(ID,Tarjeta) || compareArray(ID, llavero)) {
            if (digitalRead(ledPin2) == HIGH) {
              for (angulo = 90; angulo>=0; angulo = angulo - 10) {
                servo.write(angulo);
              }
              digitalWrite(ledPin2, LOW);
              digitalWrite(buzzer, HIGH);
              delay(100);
              digitalWrite(buzzer, LOW);
            } else {
              for (angulo = 0; angulo<=90; angulo = angulo + 10) {
                servo.write(angulo);
              }
              digitalWrite(ledPin2, HIGH);
              digitalWrite(buzzer, HIGH);
              delay(100);
              digitalWrite(buzzer, LOW);
            }
          } 
          else {
            digitalWrite(ledPin1, HIGH);
            delay(1000);
            digitalWrite(ledPin1, LOW);
          }
         

         Serial.println();
         //digitalWrite(ledPin1, HIGH);

         // Finalizar lectura actual
         mfrc522.PICC_HaltA();
      }
   }
   delay(250);
}

boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
