/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 *
 * This file is part of brewflow.
 * 
 * brewflow is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * brewflow is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with brewflow.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    int nop[] = {23, temp_1*10, temp_2*10, temp_3*10, temp_4*10, temp_5*10, temp_6*10, target_temp_1, target_temp_2, target_temp_3*10, target_temp_4*10, target_temp_5*10, target_temp_6*10, heat_1_speed, heat_2_speed, pumpspeed_1, pumpspeed_2, mlttState, hlttState, vrg1, vrg2, millis()/1000};
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

void pump_set1(int wspeed){
  if (wspeed > 100) {
    wspeed = 100;
  }
  if (wspeed > 0) {
    pumpspeed_1 = wspeed * 255 / 100;
    analogWrite(pump1, wspeed);
    pumpstate_1 = HIGH;
  }
  else {
    analogWrite(pump1, 0);
    pumpspeed_1 = 0;
    pumpstate_1 = LOW;
  } 
}

void pump_set2(int wspeed){
  if (wspeed > 100) {
    wspeed = 100;
  }
  if (wspeed > 0) {
    pumpspeed_2 = wspeed * 255 / 100;
    analogWrite(pump2, wspeed);
    pumpstate_2 = HIGH;
  }
  else {
    analogWrite(pump2, 0);
    pumpspeed_2 = 0;
    pumpstate_2 = LOW;
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
