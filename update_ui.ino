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

void update_ui(int tempupdate){
  if (millis() >= (lastupdateui + tempupdate)){
    lastupdateui =  millis();
    Serial.println(""); 
    if (commands == 1){
      Serial.println("Commands");
      Serial.println("--------");
      Serial.println("9010xx: Set target temp. xx = temp in celcius");
      Serial.println("9015xx: Set timer. xx = time in minutes");
      Serial.println("90191: Water added acknowledge");
      Serial.println("9020xx: Pump on. xxx = speed in percentage"); 
      Serial.println("9025: Pump off"); 
      Serial.println("9030xx: Heat on. xx = temp in celcius");
      Serial.println("9035: Heat off");
      Serial.println("9070: Step start");
      Serial.println("9999: Reset"); 
      Serial.println("");
      }
    Serial.println("---------------");
    Serial.print("| Update @ ");
    Serial.print(millis()/1000);
    Serial.println(" |");
    Serial.println("--------------------------------------------");
    Serial.println("|             BrewFlow v0.1b               |");
  if (ilock == true){
Serial.println("|              System Ready                |");
}
else 
{
Serial.println("|               System Idle                |");
}
Serial.println("--------------------------------------------");

Serial.print("  MLT temp [top: ");
Serial.print(temp1);
Serial.print("] [bottom: ");
Serial.print(temp2);
Serial.println("]");
Serial.println("--------------------------------------------");

Serial.print("  MLT [pump: ");

if (pump1state == 0){
  Serial.print(" OFF]");
}
else
{
Serial.print(pump1speed/255 * 100);
    Serial.print("%]");
}
Serial.print("[ Heat: ");

if (vrg == 0){
  Serial.println(" OFF]");
}
else
{
    Serial.print(intensity);  
    Serial.println("% ON]");
}
Serial.println("--------------------------------------------");

Serial.println(""); 
   
Serial.print("Target temp.: ");
Serial.println(target);
Serial.print("Timer.......: ");
Serial.println(steptimer);
  }  
}
