#include <EEPROM.h>
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
  //EEPROM.write(0,0);
  if(EEPROM.read(0) == 0) {
    // Configuración inicial
    servoHombro.write(10);
    servoCodo.write(60);
    servoMuneca.write(10);
    servoPinza.write(18);
  } else {
    ejecucion = true;
    programacion = false;
    creacionArreglo = false;
    servoHombro.write(EEPROM.read(3));
    servoCodo.write(EEPROM.read(4));
    servoMuneca.write(EEPROM.read(5));
    servoPinza.write(EEPROM.read(6));
    for(int i = 0; i < EEPROM.read(7); i++) {
      pasos[i][0] = EEPROM.read(i*2+8);
      pasos[i][1] = EEPROM.read(i*2+9);
    }
    Serial.println("Valores guardados en la EEPROM");
    for(int i = 0; i < 10; i ++) {
      Serial.println(EEPROM.read(i));
    }
    
    
  }

  
  
}
 
void loop() {
  // Ejecución automática de la programación guardada
  if(ejecucion) {      
    ejecutarProgramacion();
  }
    
  // Indicar al usuario que está en modo programación
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
    leerDatos();
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
      //EEPROM.write(0,0);
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
        programacionCintura();
      }

      if(programarHombro && input > 7 && input < 120) {
        programacionHombro();
      }

      if(programarCodo && input > 7 && input < 120) {        
        programacionCodo();
      }

      if(programarMuneca && input > 7 && input < 120) {        
        programacionMuneca();
      }

      if(programarPinza && input > 7 && input < 120) {        
        programacionPinza();
      }
      
    } // Fin de la parte de programación de servos


    
    
  }
} // Fin loop


void paroEmergencia() {
  botonPresionado = true;
  digitalWrite(LEDROJO, HIGH);
  tone(BUZZER, 1000);
}