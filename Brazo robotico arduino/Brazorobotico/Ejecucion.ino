void ejecutarProgramacion() {
  digitalWrite(LEDVERDE, HIGH);
  noTone(BUZZER);
  Serial.println("Reposicionando...");
  delay(1000);

  if(EEPROM.read(0) == 0) {
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
  } else {
    int valorCargadoMotorAPasos = EEPROM.read(2);
    valorMotorPasos = valorCargadoMotorAPasos * 16;
    delay(20);
    servoHombro.write(EEPROM.read(3));
    delay(100);
    servoCodo.write(EEPROM.read(4));
    delay(100);
    servoMuneca.write(EEPROM.read(5));
    delay(100);
    servoPinza.write(EEPROM.read(6));
    delay(100);
  }
  
  boolean regresaALaPosicionInicial = false;
  EEPROM.write(0,1);
  int pasoActualCargado;
  if(EEPROM.read(1) == EEPROM.read(7)) pasoActualCargado = 0;
  else pasoActualCargado = EEPROM.read(1);
  
  for(int i = pasoActualCargado; i < EEPROM.read(7); i++) {
    input = Serial.parseInt();
    if(botonPresionado || input == 9) {
      colocarPosicionInicial();
      digitalWrite(LEDROJO, LOW);
      digitalWrite(LEDVERDE, LOW);
      noTone(BUZZER);
      botonPresionado = false;

      EEPROM.write(0,0);
      EEPROM.write(1,0);
      
      break;
    }
    
    if(regresaALaPosicionInicial) {
      // Colocar motores a la posición inicial
      colocarPosicionInicial();
      regresaALaPosicionInicial = false;
    }
    
    switch(pasos[i][0]) {                      
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

      case 6:
        //Serial.print("VALOR");
        //Serial.println(valorMotorPasos);
        int temp = pasos[i][1] * 16;
        
        Serial.print("temp: ");
        Serial.println(temp);
        if(temp >= valorMotorPasos) {
          Serial.println("Avanza");
          for (int i = valorMotorPasos; i <= temp; i++) {
            clockwise();
            Serial.println(i);
            delayMicroseconds(motorSpeed);
          }
        }
        else {
          for (int i = valorMotorPasos; i >= temp; i--) {
            anticlockwise();
            Serial.println(i);
            delayMicroseconds(motorSpeed);
          }
        }
        valorMotorPasos = temp;
        int division = valorMotorPasos/16;
        Serial.print("Valor guardado: ");
        Serial.println(division);
        EEPROM.write(2, division);
        break;
         
    }
    
    EEPROM.write(1, i+1);
    
    EEPROM.write(3, servoHombro.read());
    EEPROM.write(4, servoCodo.read());
    EEPROM.write(5, servoMuneca.read());
    EEPROM.write(6, servoPinza.read());
    
    if(i == EEPROM.read(7)-1) {
      i = -1;
      regresaALaPosicionInicial = true;
    }
    delay(tiempoEsperaEntrePasos);        
  }
}
