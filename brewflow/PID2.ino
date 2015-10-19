/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 * PID Copyright 2001 - 2015 Emile van de Logt
 * <http://www.vandelogt.nl>
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

void init_pid_2() {
  v2ts_ticks = (int)((v2ts * 1000.0) / T_50MSEC);
  if (v2ts_ticks > TWENTY_SECONDS) {
   v2ts_ticks = TWENTY_SECONDS;
  }
  if (v2ti == 0.0) {
    v2k0 = 0.0;
  }
  else {
    v2k0 = v2kc * v2ts / v2ti;
  }
  v2k1 = v2kc * v2td / v2ts;
  v2lpf1 = (2.0 * v2k_lpf - v2ts) / (2.0 * v2k_lpf + v2ts);
  v2lpf2 = v2ts / (2.0 * v2k_lpf + v2ts);
}

void update_pid_2() {
  double v2ek;
  double v2lpf;
  v2ek = target_temp_2 - temp_3;
  if (vrg2){
    v2pp = v2kc * (v2xk_1 - temp_3);
    v2pi = v2k0 * v2ek;
    v2pd = v2k1 * (2.0 * v2xk_1 - temp_3 - v2xk_2);
    heat_2_speed += v2pp + v2pi + v2pd;
  }
  else { 
    heat_2_speed = v2pp = v2pi = v2pd = 0.0; 
  }
  v2xk_2 = v2xk_1;
  v2xk_1 = temp_3;
  if (heat_2_speed > GMA_HLIM) {
    heat_2_speed = GMA_HLIM;
  }
  else if (heat_2_speed < GMA_LLIM) {
    heat_2_speed = GMA_LLIM;
  }
  analogWrite(heat_2, heat_2_speed);
} 
