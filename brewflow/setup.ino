/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 * PID Copyright 2001 - 2015 Emile van de Logt
 * <http://www.vandelogt.nl>
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

void setup() { 
  init_pid_1();
  init_pid_2();
  sensors.begin();
  delay(2);
  wdt_enable(WDTO_8S);
  int temp_sens = (sensors.getDeviceCount(), DEC);
  
  analogReference(EXTERNAL);
  
  pinMode(heat_1, OUTPUT);
  pinMode(heat_2, OUTPUT); 
  pinMode(pump_1_ctrl, OUTPUT);
  pinMode(pump_2_ctrl, OUTPUT);
  pinMode(pump_3_ctrl, OUTPUT);
  digitalWrite(pump_1_ctrl, HIGH);
  digitalWrite(pump_2_ctrl, HIGH);
  digitalWrite(pump_3_ctrl, HIGH); 
  analogWrite(heat_1, LOW);
  analogWrite(heat_2, LOW); 
  
  Serial.begin(57600);
}
