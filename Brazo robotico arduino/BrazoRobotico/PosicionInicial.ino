void colocarPosicionInicial() {
  // Cintura                
  if(2038 > valorMotorPasos) {
    
    for (int i = valorMotorPasos; i <= 2038; i++) {
      clockwise();
      Serial.println(i);
      delayMicroseconds(motorSpeed);
    }
  }
  else {
    Serial.println("Retrocede");
    for (int i = valorMotorPasos; i >= 2038; i--) {
      anticlockwise();
      Serial.println(i);
      delayMicroseconds(motorSpeed);
    }
  }
  valorMotorPasos = 2038;
  
  // Hombro      
  for(int k = servoHombro.read(); k >= 10; k--) {
    servoHombro.write(k);        
    delay(velocidadPorPaso);        
  }
  // Codo
  if(servoCodo.read() > 60) {
    for(int k = servoCodo.read(); k >= 60; k--) {
      servoCodo.write(k);
      delay(velocidadPorPaso);
    }
  } else {
    for(int k = servoCodo.read(); k <= 60; k++) {
      servoCodo.write(k);
      delay(velocidadPorPaso);
    }
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
}
