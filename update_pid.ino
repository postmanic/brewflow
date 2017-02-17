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
 
  ticks = (int)((ts * 1000.0) / T_50MSEC);
  if (ticks > TWENTY_SECONDS) {
    ticks = TWENTY_SECONDS;
  }
  if (ti == 0.0) {
    k0 = 0.0;
  }
  else {
    k0 = kc * ts / ti;
  }
  k1 = kc * td / ts;
  lpf1 = (2.0 * k_lpf - ts) / (2.0 * k_lpf + ts);
  lpf2 = ts / (2.0 * k_lpf + ts);
}

void update_pid() {
  double ek;
  double lpf;
  ek = target - temp1;
  if (vrg){
    pp = kc * (xk_1 - temp1);
    pi = k0 * ek;
    pd = k1 * (2.0 * xk_1 - temp1 - xk_2);
    intensity += pp + pi + pd;
  }
  else { 
    intensity = pp = pi = pd = 0.0; 
  }
  xk_2 = xk_1;
  xk_1 = temp1;
  if (intensity > GMA_HLIM) {
    intensity = GMA_HLIM;
  }
  else if (intensity < GMA_LLIM) {
    intensity = GMA_LLIM;
  }
  analogWrite(heat1, intensity);
} 
