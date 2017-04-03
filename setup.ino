/*
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

//0x28, 0x75, 0xE8, 0x26, 0x06, 0x00, 0x00, 0x21

//0x28, 0xFF, 0x69, 0x15, 0x06, 0x00, 0x00, 0xC2

void setup() { 

  //wdt_enable(WDTO_8S); // Safety first

 Serial.begin(57600);
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(2,0);
 lcd.print("brewflow 0.3"); // print a simple message
  delay(2000);
  sensors.begin();
  sensors.setResolution(T1, 11); // 375 ms
  sensors.setResolution(T2, 11);
  if (debug){
  Serial.print("Debug mode");
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Debug mode");
  delay(2000);
  
  }
  else {
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Found ");
  lcd.print(sensors.getDeviceCount(), DEC); 
  lcd.print(" devices");
  delay(2000);


  
  }
  
  analogReference(EXTERNAL);
  
  pinMode(heatcontrol, OUTPUT);
  pinMode(pump1ctrl, OUTPUT);
  
  analogWrite(heatcontrol, LOW);
  
  Serial.begin(57600);
  //Serial.println("BrewFlow Ready!");


}
