/* Procedimiento para traducir y guardar los valores de los motores a un arreglo */
void leerDatos() {  
  const int LONGITUDENTRADA = 1000;
  // Arreglo de caracteres para los valores de los servos a leer
  char inputByte[LONGITUDENTRADA + 1];
  byte size = Serial.readBytes(inputByte, LONGITUDENTRADA);
  inputByte[size] = 0;

  char* command = strtok(inputByte, ";");
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
      input = 10; // Para terminar de leer datos
/
      pasos[contadorPasosBrazo][0] = servoId;
      if(pasos[contadorPasosBrazo][0] == 6) pasos[contadorPasosBrazo][1] = position/16;
      else pasos[contadorPasosBrazo][1] = position;
      contadorPasosBrazo++;
    }
    command = strtok(0, ";");            
  }
  
  if(input == 10) {        
      EEPROM.write(0,0);      // Si está ejecutando o no (0 no, 1 sí)
      EEPROM.write(1,0);
      EEPROM.write(7,contadorPasosBrazo); // Total de pasos
      Serial.println("Arreglo guardado:");
      
    for(int i = 0; i < contadorPasosBrazo; i++) {
      Serial.print("ServoId: ");
      Serial.print(pasos[i][0]);
      Serial.print(", valor: ");
      Serial.println(pasos[i][1]);
      // Guardar valores del arreglo
      EEPROM.write(i*2 + 8,pasos[i][0]);
      int pasosStepperMotorAGuardar;
      EEPROM.write(i*2 + 9,pasos[i][1]);              
    }
  }    
}
