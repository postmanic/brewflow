void read_temperatures(){
  sensors.requestTemperatures(); 
 
  temp_1 = sensors.getTempCByIndex(0);
  delay(2);
  temp_3 = sensors.getTempCByIndex(1); 
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

void update_status(){
  if (millis() >= (lastupdatestat + 900)){
    lastupdatestat =  millis();
    int nop[] = {23, temp_1*10, temp_2*10, temp_3*10, temp_4*10, temp_5*10, temp_6*10, target_temp_1, target_temp_2, target_temp_3*10, target_temp_4*10, target_temp_5*10, target_temp_6*10, heat_1_speed, heat_2_speed, pumpspeed[0], pumpspeed[1], pumpspeed[2], mlttState, hlttState, vrg1, vrg2, millis()/1000};
    send_data(1010, nop);
  }	
}

void serialEvent() {
  while (Serial.available()) {
    int inChar = Serial.read();
    inputString += (char)inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


 
void send_data(int Command, int nop[]){
  Serial.print(Command);
  for (int x = 0;x<nop[0];x++){
    Serial.print(",");
    Serial.print(nop[x]);
  }
  Serial.println();
}
