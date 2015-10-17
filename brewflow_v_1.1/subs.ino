void Aflaes_Temperaturer(){
  sensors.requestTemperatures(); 
 
  temp_1 = sensors.getTempCByIndex(0);
  delay(2);
  temp_2 = sensors.getTempCByIndex(1); 
  delay(2);
  //temp_3 = sensors.getTempCByIndex(2);
  delay(2);
  //temp_4 = sensors.getTempCByIndex(3); 
  delay(2);
  //temp_5 = sensors.getTempCByIndex(4); 
  delay(2);
  //temp_6 = sensors.getTempCByIndex(5); 
  delay(2);
}

void Opdater_Status(){
  if (millis() >= (lastupdatestat + 900)){
    lastupdatestat =  millis();
    int nop[] = {21, temp_1*10, temp_2*10, temp_3*10, temp_4*10, temp_5*10, temp_6*10, target_temp_1, target_temp_2, target_temp_3*10, target_temp_4*10, target_temp_5*10, target_temp_6*10, heat_1_speed, heat_2_speed, pump_1_speed, pump_2_speed, pump_3_speed, mlttState, hlttState, millis()/1000};
    SendData(1010, nop);
  }	
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
 
void SendData(int Command, int nop[]){
  Serial.print(Command);
  for (int x = 0;x<nop[0];x++){
    Serial.print(",");
    Serial.print(nop[x]);
  }
  Serial.println();
}
