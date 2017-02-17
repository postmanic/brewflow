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

void update_ui(int tempupdate){
  if (millis() >= (lastupdateui + tempupdate)){
    lastupdateui =  millis();
    Serial.println(""); 
    if (commands == 1){
      Serial.println("Commands");
      Serial.println("--------");
      Serial.println("9010xx: Set Mash In Temp. xx = temp in celcius");
      Serial.println("901xyy: Set step Temp. x = step. yy = temp in celcius");      
      Serial.println("902xyy: Set step timer. x = step. yy = time in minutes");
      Serial.println("9030xx: Set Boil timer. = time in minutes");      
      Serial.println("90411: Water added acknowledge");
      Serial.println("90422: Malt added acknowledge");      
      Serial.println("9050: Brew start");
      Serial.println("9999: Reset"); 
      Serial.println("");
      }
    Serial.println("---------------");
    Serial.print("| Update @ ");
    Serial.print(steptimer);
    Serial.print(" | ");
    Serial.println(millis()/1000);    
    Serial.print("Case: ");   
    Serial.println(step_x);  
    Serial.println("--------------------------------------------");

  if (ilock == true && step_x == 0){
    Serial.println("|             BrewFlow v0.1b               |");
    Serial.println("|              System Ready                |");
  }
  
  if (ilock == false && step_x == 0){ 
    Serial.println("|             BrewFlow v0.1b               |");
    Serial.println("|              !!ADD WATER!!               |");
  }

  if (ilock == true && step_x == 1){ 
    Serial.println("|                 Mash In                  |");
    Serial.println("|           Reaching Mash In Temp          |");
  }

  if (ilock == true && step_x == 2){ 
    Serial.println("|                 Mash In                 |");
    Serial.println("|     ** Add ingredients and continue **  |");
  }


  if (ilock == true && step_x == 3){ 
    Serial.println("|                 Step 1                  |");
    Serial.println("|          ** Timer running  **           |");
  }

  if (ilock == true && step_x == 4){ 
    Serial.println("|                 Step 2                  |");
    Serial.println("|          ** Timer running  **           |");
  }
  if (ilock == true && step_x == 5){ 
    Serial.println("|                 Step 3                  |");
    Serial.println("|          ** Timer running  **           |");
  }
  if (ilock == true && step_x == 6){ 
    Serial.println("|                 Step 4                  |");
    Serial.println("|          ** Timer running  **           |");
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
Serial.print("Mash In Temp..: ");
Serial.println(target1);
Serial.print("Step 1 - Temp.: ");
Serial.print(target2);
Serial.print("  Timer.: ");
Serial.println(steptimer1);
Serial.print("Step 2 - Temp.: ");
Serial.print(target3);
Serial.print("  Timer.: ");
Serial.println(steptimer2);
Serial.print("Step 3 - Temp.: ");
Serial.print(target4);
Serial.print("  Timer.: ");
Serial.println(steptimer3);
Serial.print("Step 4 - Temp.: ");
Serial.print(target5);
Serial.print("  Timer.: ");
Serial.println(steptimer4);
Serial.print("Mash Out Temp.: ");
Serial.println(target6);
Serial.print("Boil..............: ");
Serial.print("  Timer.: ");
Serial.println(steptimer5);
  }
  }  

