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

double kc = 1.2, ti = 2.5, td = 0.5, ts = 5;
double k0, k1, k2, k3, pp, pi, pd;
double ek, ek_1, ek_2, xk_1, xk_2, yk_1, yk_2;

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
    temp[0] = temp[1];    
    lastupdatepid =  millis()/1000;
    ek = target[0] - temp[0];
    if (vrg){
      pp = kc * (xk_1 - temp[0]);
      pi = k0 * ek;
      pd = k1 * (2.0 * xk_1 - temp[0] - xk_2);
      intensity += pp + pi + pd;
    }
    else { 
      intensity = pp = pi = pd = 0.0; 
    }
    xk_2 = xk_1;
    xk_1 = temp[0];
    if (intensity > 100) {
      intensity = 100;
    }
    else if (intensity < 0) {
      intensity = 0;
    }
    analogWrite(heat_control, intensity);
  }
}
