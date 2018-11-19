void programacionCintura() {
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

void programacionHombro() {
  Serial.print("Hombro: ");  
  Serial.println(input);
  servoHombro.write(input);
  delay(100);
}

void programacionCodo() {
  Serial.print("Codo: ");  
  Serial.println(input);
  servoCodo.write(input);
  delay(100);
}

void programacionMuneca() {
  Serial.print("Muñeca: ");  
  Serial.println(input);
  servoMuneca.write(input);
  delay(200);
}

void programacionPinza() {
  Serial.print("Pinza: ");  
  Serial.println(input);
  servoPinza.write(input);
  delay(100);
}
