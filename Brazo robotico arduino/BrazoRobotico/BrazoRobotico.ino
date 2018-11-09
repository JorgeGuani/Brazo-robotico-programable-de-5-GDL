#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servo;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servo.attach(9);
}
 
void loop() {
  servo.write(0);
  
}
