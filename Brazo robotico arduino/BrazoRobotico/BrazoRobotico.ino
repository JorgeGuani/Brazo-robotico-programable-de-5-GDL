#include <Servo.h>

// Declaramos las variables para controlar cada servomotor
Servo servoHombro;
Servo servoCodo;
Servo servoMuneca;
Servo servoPinza;

// Variable para la entrada serial
long input = 0;

// Banderas para el control de configuración
boolean programacion = false;
boolean ejecucion = false;
boolean programarCintura = false;
boolean programarHombro = false;
boolean programarCodo = false;
boolean programarMuneca = false;
boolean programarPinza = false;
 
void setup() {
  Serial.begin(9600);  
  
  // Se inician los servos
  servoHombro.attach(5);
  servoCodo.attach(6);
  servoMuneca.attach(9);
  servoPinza.attach(10);
  
  // Configuración inicial
  servoHombro.write(20);
  servoCodo.write(20);
  servoMuneca.write(20);
  servoPinza.write(20);
}
 
void loop() {    
  while (Serial.available() == 0) { }
  input = Serial.parseInt();

  if(input > 0) {
    if(input == 1) {
      programacion = true;
      ejecucion = false;
      delay(100);
    }
    
    if(input == 2) {
      programacion = false;
      ejecucion = true;
      delay(100);
    }
    
    if(programacion) {
      Serial.println("Programacion");
      if(input == 3) {      //Cintura
        programarCintura = true;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = false;
        delay(100);
      }
      else if(input == 4) { //Hombro
        programarCintura = false;
        programarHombro = true;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = false;
        delay(100);
      }
      else if(input == 5) { //Codo
        programarCintura = false;
        programarHombro = false;
        programarCodo = true;
        programarMuneca = false;
        programarPinza = false;
        delay(100);
      }
      else if(input == 6) { //Muñeca
        programarCintura = false;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = true;
        programarPinza = false;
        delay(100);
      }
      else if(input == 7) { //Pinza
        programarCintura = false;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = true;
        delay(100);
      }

      if(programarCintura && input > 7) {
        Serial.println("Cintura");
        delay(100);
      }

      if(programarHombro && input > 7) {
        Serial.print("Hombro: ");  
        Serial.println(input);
        servoHombro.write(input);
        delay(100);
      }

      if(programarCodo && input > 7) {        
        Serial.print("Codo: ");  
        Serial.println(input);
        servoCodo.write(input);
        delay(100);
      }

      if(programarMuneca && input > 7) {        
        Serial.print("Muñeca: ");  
        Serial.println(input);
        servoMuneca.write(input);
        delay(200);
      }

      if(programarPinza && input > 7) {        
        Serial.print("Pinza: ");  
        Serial.println(input);
        servoPinza.write(input);
        delay(100);
      }
      
    } // Fin de la programación        
    
  }
  /*if (Serial.available()) {
    
    delay(100);
    input = Serial.read();

    if (Serial.available() > 0) {
      if (input == '1') {
        Serial.println("programar");
        while (input == '1') {
          //Serial.println("Está en programacion");
          if (Serial.read() == '3') {
            programarCintura();
          }
          else if (Serial.read() == '4') {
            programarHombro();
          }
          //else if (Serial.read() != 10) break; //Si se detecta un cambio en la entrada serial
        }
      }

      if (input == '2') {
        Serial.println("ejecutar");
      }
    }*/  
}

/*void programar() {
  
}

void programarCintura() {
  Serial.println("Cintura: ");
}

void programarHombro() {
  Serial.println("Esta en hombro");
  while (Serial.available() == 0) { }
  input = Serial.parseInt();

  if(input > 0) {
    Serial.print("Hombro: ");  
    Serial.println(input);
    //servoHombro.write(input);
  }
}*/
