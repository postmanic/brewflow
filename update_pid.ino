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

void init_pid() {
  if (ti == 0.0) {
    k0 = 0.0;
  }
  else {
   k0 = kc * ts / ti;
  }
  k1 = kc * td / ts;
}

void update_pid() {
    temp[0] = temp[1];     
  if (millis()/1000 >= (lastupdatepid + 20)){
    lastupdatepid =  millis()/1000;
    ek = steptarget - temp[0];
    if (vrg){
      pp = kc * (xk_1 - temp[0]);
      pi = k0 * ek;
      pd = k1 * ((2.0 * xk_1) - temp[0] - xk_2);
      heatspeed += pp + pi + pd;
    }
    else { 
      heatspeed = pp = pi = pd = 0.0; 
    }
    xk_2 = xk_1;
    xk_1 = temp[0];
    if (heatspeed > 100) {
      heatspeed = 100;
    }
    else if (heatspeed < 0) {
      heatspeed = 0;
    }
    analogWrite(heatcontrol, (heatspeed * 255) / 100);
    Serial.println(pp);
  }
}
