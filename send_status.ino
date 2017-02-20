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
   int nop[] = {12, temp[0], temp[1], temp[2], ilock, mlock, vrg, intensity, pump1state, pump1speed, step_x, lastupdatestatus}; 
   send_data(1010, nop);  
  }
}

void send_settings(){
  int nop[] = {15, target[0],target[1], target[2], target[3], target[4], target[5], target[6], target[7], steptimer[0], steptimer[1], steptimer[2], steptimer[3], steptimer[4], steptimer[5]}; 
  send_data(1011, nop);  
}

