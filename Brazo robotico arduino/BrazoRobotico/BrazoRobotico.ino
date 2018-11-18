#include <Servo.h>

// Leds y botón
#define LEDVERDE 3
#define LEDROJO  13
#define BOTON    2
#define BUZZER   11

boolean botonPresionado = false;

// Declaramos las variables para controlar cada servomotor
Servo servoHombro;
Servo servoCodo;
Servo servoMuneca;
Servo servoPinza;

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

// Banderas para el control de configuración
boolean programacion = false;
boolean ejecucion = false;
boolean programarCintura = false;
boolean programarHombro = false;
boolean programarCodo = false;
boolean programarMuneca = false;
boolean programarPinza = false;
boolean creacionArreglo = false;

// Arreglo que guarda la programación de los motores
int pasos[100][2];

// Contador de los pasos guardados del brazo
int contadorPasosBrazo;
int velocidadPorPaso = 20;
int tiempoEsperaEntrePasos = 300;

 
void setup() {
  Serial.begin(9600);  

  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BOTON, INPUT);    
  attachInterrupt(digitalPinToInterrupt(BOTON), paroEmergencia, RISING);
  
  // Se inician los servos
  servoHombro.attach(5);
  servoCodo.attach(6);
  servoMuneca.attach(9);
  servoPinza.attach(10);

  // Declarar pines del motor a pasos como salida
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  // Configuración inicial
  servoHombro.write(10);
  servoCodo.write(60);
  servoMuneca.write(10);
  servoPinza.write(18);
}
 
void loop() {
  
  
  while (Serial.available() == 0) {    
    if(programacion) {
      digitalWrite(LEDVERDE, HIGH);
      delay(50);
      digitalWrite(LEDVERDE, LOW);
      delay(50);
      digitalWrite(LEDVERDE, HIGH);
      delay(50);
      digitalWrite(LEDVERDE, LOW);
      delay(500);     
    }  
  }
  
  if(creacionArreglo) {
    const int LONGITUDENTRADA = 1000;
    // Arreglo de caracteres para los valores de los servos a leer
    char inputByte[LONGITUDENTRADA + 1];
    byte size = Serial.readBytes(inputByte, LONGITUDENTRADA);
    inputByte[size] = 0;
  
    char* command = strtok(inputByte, ";");
    //int pasos[size][2];
    contadorPasosBrazo = 0;
    while (command != 0) {
      // Partir el string en 2, reemplazar la "," por un "0"
      char* separator = strchr(command, ',');
      if (separator != 0) {
        *separator = 0;
        int servoId = atoi(command);
        ++separator;
        int position = atoi(separator);

        creacionArreglo = false;
        input = 10;
        
        //Guardar los valores en el arreglo de los servos        
        Serial.print("Servo ID: ");
        Serial.println(servoId);
        Serial.print("Valor: ");
        Serial.println(position);
        Serial.println("");
        pasos[contadorPasosBrazo][0] = servoId;
        pasos[contadorPasosBrazo][1] = position;
        contadorPasosBrazo++;
      }
      command = strtok(0, ";");            
    }
    
    if(input == 10) {
      Serial.println("Arreglo guardado:");
      for(int i = 0; i < contadorPasosBrazo; i++) {
        Serial.print("ServoId: ");
        Serial.print(pasos[i][0]);
        Serial.print(", valor: ");
        Serial.println(pasos[i][1]);
      }
    }
    
  }
  else {
    input = Serial.parseInt();
  }
  
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

      if(programarCintura && input > 7 && input < 4076) {
        Serial.println("Cintura");
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
        Serial.print("Hombro: ");  
        Serial.println(input);
        servoHombro.write(input);
        delay(100);
      }

      if(programarCodo && input > 7 && input < 120) {        
        Serial.print("Codo: ");  
        Serial.println(input);
        servoCodo.write(input);
        delay(100);
      }

      if(programarMuneca && input > 7 && input < 120) {        
        Serial.print("Muñeca: ");  
        Serial.println(input);
        servoMuneca.write(input);
        delay(200);
      }

      if(programarPinza && input > 7 && input < 120) {        
        Serial.print("Pinza: ");  
        Serial.println(input);
        servoPinza.write(input);
        delay(100);
      }
      
    } // Fin de la parte de programación de servos


    // Ejecución automática de la programación guardada
    if(ejecucion) {
      digitalWrite(LEDVERDE, HIGH);
      noTone(BUZZER);
      Serial.println("Reposicionando...");
      delay(1000);

      // Colocar motores a la posición inicial
      Serial.println("Posición inicial");
      
      // Hombro      
      for(int i = servoHombro.read(); i >= 10; i--) {
        servoHombro.write(i);        
        delay(100);        
      }
      Serial.print("Hombro: ");
      Serial.println(servoHombro.read());

      // Codo
      for(int i = servoCodo.read(); i >= 60; i--) {
        servoCodo.write(i);
        delay(100);
      }
      Serial.print("Codo: ");
      Serial.println(servoCodo.read());

      // Muñeca
      for(int i = servoMuneca.read(); i >= 10; i--) {
        servoMuneca.write(i);
        delay(velocidadPorPaso);
      }
      Serial.print("Muñeca: ");
      Serial.println(servoMuneca.read());

      // Pinza
      for(int i = servoPinza.read(); i >= 18; i--) {
        servoPinza.write(i);
        delay(velocidadPorPaso);
      }
      Serial.print("Pinza: ");
      Serial.println(servoPinza.read());

      delay(500);
      Serial.println("Ejecución...");
      delay(500);

      // Coloca el brazo en la posición inicial
      Serial.print("Pasos del robot: ");
      Serial.println(contadorPasosBrazo);
      
      boolean regresaALaPosicionInicial = false;
      
      for(int i = 0; i < contadorPasosBrazo; i++) {
        if(botonPresionado) {
          // Hombro      
          for(int k = servoHombro.read(); k >= 10; k--) {
            servoHombro.write(k);        
            delay(15);        
          }
          // Codo
          for(int k = servoCodo.read(); k >= 60; k--) {
            servoCodo.write(k);
            delay(5);
          }
    
          // Muñeca
          for(int k = servoMuneca.read(); k >= 10; k--) {
            servoMuneca.write(k);
            delay(2);
          }
    
          // Pinza
          for(int k = servoPinza.read(); k >= 18; k--) {
            servoPinza.write(k);
            delay(velocidadPorPaso-5);
          }
          digitalWrite(LEDROJO, LOW);
          digitalWrite(LEDVERDE, LOW);
          noTone(BUZZER);
          botonPresionado = false;
          break;
        }
        
        if(regresaALaPosicionInicial) {
            // Colocar motores a la posición inicial      
          // Hombro      
          for(int k = servoHombro.read(); k >= 10; k--) {
            servoHombro.write(k);        
            delay(velocidadPorPaso);        
          }
          // Codo
          for(int k = servoCodo.read(); k >= 60; k--) {
            servoCodo.write(k);
            delay(velocidadPorPaso);
          }
    
          // Muñeca
          for(int k = servoMuneca.read(); k >= 10; k--) {
            servoMuneca.write(k);
            delay(velocidadPorPaso);
          }
    
          // Pinza
          for(int k = servoPinza.read(); k >= 18; k--) {
            servoPinza.write(k);
            delay(velocidadPorPaso/2);
          }
          regresaALaPosicionInicial = false;
        }
        
        switch(pasos[i][0]) {
          case 1:
            
            break;
            
          case 2:
            if(pasos[i][1] > servoHombro.read()) {
              for(int j = servoHombro.read(); j <= pasos[i][1]; j++) {
                servoHombro.write(j);
                delay(velocidadPorPaso);
              }              
            } else {
              for(int j = servoHombro.read(); j >= pasos[i][1]; j--) {
                servoHombro.write(j);
                delay(velocidadPorPaso);
              }                     
            }
            Serial.print("Hombro: ");
            Serial.println(servoHombro.read()); 
            break;
            
          case 3:
            if(pasos[i][1] > servoCodo.read()) {
              for(int j = servoCodo.read(); j <= pasos[i][1]; j++) {
                servoCodo.write(j);
                delay(velocidadPorPaso);
              }               
            } else {
              for(int j = servoCodo.read(); j >= pasos[i][1]; j--) {
                servoCodo.write(j);
                delay(velocidadPorPaso);
              }                     
            }
            Serial.print("Codo: ");
            Serial.println(servoCodo.read());
            break;
            
          case 4:
            if(pasos[i][1] > servoMuneca.read()) {
              for(int j = servoMuneca.read(); j <= pasos[i][1]; j++) {
                servoMuneca.write(j);
                delay(velocidadPorPaso);
              }               
            } else {
              for(int j = servoMuneca.read(); j >= pasos[i][1]; j--) {
                servoMuneca.write(j);
                delay(velocidadPorPaso);
              }                     
            }
            Serial.print("Muñeca: ");
            Serial.println(servoMuneca.read());
            break;
            
          case 5:
            if(pasos[i][1] > servoPinza.read()) {
              for(int j = servoPinza.read(); j <= pasos[i][1]; j++) {
                servoPinza.write(j);
                delay(velocidadPorPaso/2);
              }               
            } else {
              for(int j = servoPinza.read(); j >= pasos[i][1]; j--) {
                servoPinza.write(j);
                delay(velocidadPorPaso/2);
              }                     
            }
            Serial.print("Pinza: ");
            Serial.println(servoPinza.read()); 
            break;
             
        }
        if(i == contadorPasosBrazo -1) {
          i = -1;
          regresaALaPosicionInicial = true;
        }
        delay(tiempoEsperaEntrePasos);        
      }

    }
    
  }
}

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

void paroEmergencia() {
  botonPresionado = true;
  digitalWrite(LEDROJO, HIGH);
  tone(BUZZER, 1000);
}
