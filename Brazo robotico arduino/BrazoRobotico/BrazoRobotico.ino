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
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);  
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoHombro.attach(5);
  servoCodo.attach(6);
  servoMuneca.attach(9);
  servoPinza.attach(10);
}
 
void loop() {
  servoHombro.write(40);
  servoCodo.write(20);
  servoMuneca.write(20);
  servoPinza.write(20);

  while (Serial.available() == 0) { }
  input = Serial.parseInt();

  if(input > 0) {
    if(input == 1) {
      programacion = true;
      ejecucion = false;
    }
    
    if(input == 2) {
      programacion = false;
      ejecucion = true;
    }
    
    if(programacion) {
      Serial.println("Programacion");
      if(input == 3) {      //Cintura
        programarCintura = true;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = false;
      }
      else if(input == 4) { //Hombro
        programarCintura = false;
        programarHombro = true;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = false;
      }
      else if(input == 5) { //Codo
        programarCintura = false;
        programarHombro = false;
        programarCodo = true;
        programarMuneca = false;
        programarPinza = false;
      }
      else if(input == 6) { //Muñeca
        programarCintura = false;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = true;
        programarPinza = false;
      }
      else if(input == 7) { //Pinza
        programarCintura = false;
        programarHombro = false;
        programarCodo = false;
        programarMuneca = false;
        programarPinza = true;
      }

      if(programarCintura) {
        Serial.println("Cintura");
      }

      if(programarHombro) {
        Serial.print("Hombro: ");  
        Serial.println(input);
        //servoHombro.write(input);
      }

      if(programarCodo) {        
        Serial.print("Codo: ");  
        Serial.println(input);
        //servoCodo.write(input);
      }

      if(programarMuneca) {        
        Serial.print("Muñeca: ");  
        Serial.println(input);
        //servoMuneca.write(input);
      }

      if(programarPinza) {        
        Serial.print("Pinza: ");  
        Serial.println(input);
        //servoPinza.write(input);
      }
      
    }        
    
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
