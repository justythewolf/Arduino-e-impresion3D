#include <Stepper.h>
 
// Esto es el número de pasos por revolución
#define STEPS 4096 
// Número de pasos que queremos que de
#define NUMSTEPS 10000
 
// Constructor, pasamos STEPS y los pines donde tengamos conectado el motor
Stepper stepper(STEPS, 5, 4, 3, 2);
 
void setup() {
  // Asignamos la velocidad en RPM (Revoluciones por Minuto)
  stepper.setSpeed(10);
}
 
void loop() {
  // Movemos el motor un número determinado de pasos
  stepper.step(NUMSTEPS);
}
