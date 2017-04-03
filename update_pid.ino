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



void update_pid(double steptarget, double xk, boolean vrg) {

  static int lastupdate;
  static double xk_1, xk_2;
  double pp, pi, pd;
  double kc = KC;
  double ti = TI;
  double td = TD;
  int ts = TS;
    
  if (millis()/1000 >= (lastupdate + ts)){
    lastupdate =  millis()/1000;
    if (vrg){
      pp = kc * (xk_1 - xk);
      pi = (kc * ts / ti) * (steptarget - xk);
      pd = (kc * td / ts) * (2.0 * xk_1 - xk - xk_2);
      yk += pp + pi + pd;
    }
    else { 
      yk = pp = pi = pd = 0.0; 
    }
    xk_2 = xk_1;
    xk_1 = xk;
    if (yk > 100) {
      yk = 100;
    }
    else if (yk < 0) {
      yk = 0;
    }
    analogWrite(heatcontrol, (yk * 255) / 100);
  }
}
