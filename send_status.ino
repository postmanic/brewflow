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

void send_status(int tempupdate){
  if (millis()/1000 >= (lastupdatestatus + tempupdate)){
    lastupdatestatus =  millis()/1000;
   int nop[] = {13, temp[0]*10, temp[1]*10, temp[2]*10, ilock, mlock, vrg, yk, pumpstate, wspeed1, step_x, steptarget, lastupdatestatus}; 
   send_data(1010, nop);
   Serial.print ("YK:");
   Serial.println (yk);
   Serial.print ("PP:");
   Serial.println (pp);
      Serial.print ("PI:");
   Serial.println (pi);
      Serial.print ("PD:");
   Serial.println (pd);
   
   
   
   
   int pop[] = {15, steptarget, mashintarget, step1target, step2target, step3target, step4target, mashouttarget, boiltarget, steptimer, step1timer, step2timer, step3timer, step4timer, boiltimer}; 
   send_data(1011, pop); 
   int kop[] = {5, pp, pi, pd, heatspeed}; 
   send_data(1012, kop);    
  }
}

void send_settings(){
  //int nop[] = {3, steptarget, steptimer};
  //send_data(1011, nop);
}

void send_setup(){
  int nop[] = {2, 2};
  send_data(1012, nop);
}


