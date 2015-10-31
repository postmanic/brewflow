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

void setup() { 

  init_pid_1();
  init_pid_2();
   
  wdt_enable(WDTO_8S); // Safety first
  
  sensors.begin(); 
  int temp_sens = (sensors.getDeviceCount(), DEC);
  
  analogReference(EXTERNAL);
  
  pinMode(heat_1, OUTPUT);
  pinMode(heat_2, OUTPUT); 
  pinMode(pump1ctrl, OUTPUT);
  pinMode(pump2ctrl, OUTPUT);

  
  analogWrite(heat_1, LOW);
  analogWrite(heat_2, LOW); 
  analogWrite(pump1ctrl, LOW);
  analogWrite(pump2ctrl, LOW); 

  
  Serial.begin(57600);
}
