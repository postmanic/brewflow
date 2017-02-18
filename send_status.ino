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
  if (millis() >= (lastupdatestat + tempupdate)){
    lastupdatestat =  millis();
   int nop[] = {10, temp, temp1, temp2, temp3, temp4, vrg, intensity, pump1state, pump1speed}; 
   send_data(1010, nop);  
  }
}
