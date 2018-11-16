#include <Servo.h>

// Declaramos las variables para controlar cada servomotor
Servo servoHombro;
Servo servoCodo;
Servo servoMuneca;
Servo servoPinza;

<<<<<<< HEAD
// Variables para el motor a pasos
const int motorPin1 = 4;    // 28BYJ48 In1
const int motorPin2 = 7;    // 28BYJ48 In2
const int motorPin3 = 8;    // 28BYJ48 In3
const int motorPin4 = 12;   // 28BYJ48 In4

int motorSpeed = 3200;      //variable para fijar la velocidad
int stepCounter = 0;        // contador para los pasos
int stepsPerRev = 4076;     // pasos para una vuelta completa

const int numSteps = 8;
const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

int valorMotorPasos = 2038;

// Variable para la entrada serial
long input = 0;
String cadena = "";
=======
// Variable para la entrada serial
long input = 0;
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031

// Banderas para el control de configuración
boolean programacion = false;
boolean ejecucion = false;
boolean programarCintura = false;
boolean programarHombro = false;
boolean programarCodo = false;
boolean programarMuneca = false;
boolean programarPinza = false;
<<<<<<< HEAD
boolean creacionArreglo = false;
=======
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
 
void setup() {
  Serial.begin(9600);  
  
  // Se inician los servos
  servoHombro.attach(5);
  servoCodo.attach(6);
  servoMuneca.attach(9);
  servoPinza.attach(10);
<<<<<<< HEAD

  // Declarar pines del motor a pasos como salida
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
=======
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
  
  // Configuración inicial
  servoHombro.write(20);
  servoCodo.write(20);
  servoMuneca.write(20);
  servoPinza.write(20);
}
 
<<<<<<< HEAD
void loop() {     
  while (Serial.available() == 0) { }

  input = Serial.parseInt();
  
  if(input > 0) {
  
    if(input == 1) {  // Para programar los pasos del robot
      programacion = true;
      ejecucion = false;
      creacionArreglo = false;
      delay(100);
    }

    if(input == 2) {  // Para recibir los pasos a ejecutar
      Serial.println("Leyendo...");
      creacionArreglo = true;
      programacion = false;
      programacion = ejecucion = false;
      delay(100);
    }
    
    if(input == 8) {  // Para realizar la ejecución automática de la programación
      programacion = false;
      ejecucion = true;
      creacionArreglo = false;
      delay(100);
    }

    // Checa cada bandera para determinar las intrucciones del arduino
=======
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
    
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
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
<<<<<<< HEAD
        if(input >= valorMotorPasos) {
          for (int i = valorMotorPasos; i < input; i++) {
            clockwise();
            Serial.println(i);
            delayMicroseconds(motorSpeed);
          }
        }
        else {
          for (int i = valorMotorPasos; i > input ; i--) {
            anticlockwise();
            Serial.println(i);
            delayMicroseconds(motorSpeed);
          }
        }
        valorMotorPasos = input;
        Serial.println(" ");
        Serial.println(valorMotorPasos);
        Serial.println(" ");
        Serial.println(" ");
        delay(100);
      }

      if(programarHombro && input > 7 && input < 120) {
=======
        delay(100);
      }

      if(programarHombro && input > 7) {
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
        Serial.print("Hombro: ");  
        Serial.println(input);
        servoHombro.write(input);
        delay(100);
      }

<<<<<<< HEAD
      if(programarCodo && input > 7 && input < 120) {        
=======
      if(programarCodo && input > 7) {        
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
        Serial.print("Codo: ");  
        Serial.println(input);
        servoCodo.write(input);
        delay(100);
      }

<<<<<<< HEAD
      if(programarMuneca && input > 7 && input < 120) {        
=======
      if(programarMuneca && input > 7) {        
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
        Serial.print("Muñeca: ");  
        Serial.println(input);
        servoMuneca.write(input);
        delay(200);
      }

<<<<<<< HEAD
      if(programarPinza && input > 7 && input < 120) {        
=======
      if(programarPinza && input > 7) {        
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
        Serial.print("Pinza: ");  
        Serial.println(input);
        servoPinza.write(input);
        delay(100);
      }
      
<<<<<<< HEAD
    } // Fin de la parte de programación de servos

    /*if(creacionArreglo && input != 2) {
      String valoresMotores;
      int pasos[input];
    }*/
=======
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
>>>>>>> 0667da4f22b887c06cc7966a4debe158c784d031
  
    if(ejecucion) {
      Serial.println("Ejecución");
      Serial.println(input);

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

void clockwise() {
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput(stepCounter);
}

void anticlockwise() {
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput(stepCounter);
}

void setOutput(int step) {
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
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
