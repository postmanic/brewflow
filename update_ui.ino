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
  if (millis()/1000 >= (lastupdateui + tempupdate)){
    lastupdateui =  millis()/1000;
   
  if (ilock == true && step_x == 0){
    Serial.println("BrewFlow v0.1b");
    Serial.println("System Ready");
  }
 // 
  //if (ilock == false && step_x == 0){ 
    //Serial.println("|             BrewFlow v0.1b               |");
    //Serial.println("|              !!ADD WATER!!               |");
    //Serial.print("1030,");
    //Serial.print("2,");
   // Serial.println("Add water");
  //}

  //if (ilock == true && step_x == 1){ 
    //Serial.println("|                 Mash In                  |");
    //Serial.println("|           Reaching Mash In Temp          |");
    //Serial.print("1030,");
    //Serial.print("2,");
    //Serial.println("Reaching Mash In Temp");
  //}

 // if (ilock == true && step_x == 2){ 
   // Serial.println("|                 Mash In                 |");
   // Serial.println("|     ** Add ingredients and continue **  |");
  //  Serial.print("1030,");
  // Serial.print("2,");
  // / Serial.println("** Add ingredients and continue **");   
 // }


  //if (ilock == true && step_x == 3){ 
    //Serial.println("|                 Step 1                  |");
    //Serial.println("|          ** Timer running  **           |");
    //Serial.print("1030,");
    //Serial.print("2,");
    //Serial.println("** Timer running **");  
  //}

  //if (ilock == true && step_x == 4){ 
  //  Serial.println("|                 Step 2                  |");
  //  Serial.println("|          ** Timer running  **           |");
  //}
 // if (ilock == true && step_x == 5){ 
 //   Serial.println("|                 Step 3                  |");
 //   Serial.println("|          ** Timer running  **           |");
 // }
 // if (ilock == true && step_x == 6){ 
 //   Serial.println("|                 Step 4                  |");
 //   Serial.println("|          ** Timer running  **           |");
 // }  

  
//Serial.println("--------------------------------------------");

//Serial.print("  MLT temp [top: ");
//Serial.print(temp[1]);
//Serial.print("] [bottom: ");
//Serial.print(temp[2]);
//Serial.println("]");
//Serial.println("--------------------------------------------");

//Serial.print("  MLT [pump: ");

//if (pump1state == 0){
 // Serial.print(" OFF]");
//}
//else
//{
//Serial.print(pump1speed/255 * 100);
 //   Serial.print("%]");
//}
//Serial.print("[ Heat: ");

//if (vrg == 0){
  //Serial.println(" OFF]");
//}
//else
//{
   // Serial.print(intensity);  
    //Serial.println("% ON]");
//}
//Serial.println("--------------------------------------------");
//Serial.println(""); 
//Serial.print("Mash In Temp..: ");
//Serial.println(target[1]);
//Serial.print("Step 1 - Temp.: ");
//Serial.print(target[2]);
//Serial.print("  Timer.: ");
//Serial.println(steptimer[1]);
//Serial.print("Step 2 - Temp.: ");
//Serial.print(target[3]);
//Serial.print("  Timer.: ");
//Serial.println(steptimer[2]);
//Serial.print("Step 3 - Temp.: ");
//Serial.print(target[4]);
//Serial.print("  Timer.: ");
//Serial.println(steptimer[3]);
//Serial.print("Step 4 - Temp.: ");
//Serial.print(target[5]);
//Serial.print("  Timer.: ");
//Serial.println(steptimer[4]);
//Serial.print("Mash Out Temp.: ");
//Serial.println(target[6]);
//Serial.print("Boil..............: ");
//Serial.print("  Timer.: ");
//Serial.println(steptimer[5]);
  }
}
