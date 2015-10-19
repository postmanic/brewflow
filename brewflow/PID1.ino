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
 
void init_pid_1() {
  v1ts_ticks = (int)((v1ts * 1000.0) / T_50MSEC);
  if (v1ts_ticks > TWENTY_SECONDS) {
    v1ts_ticks = TWENTY_SECONDS;
  }
  if (v1ti == 0.0) {
    v1k0 = 0.0;
  }
  else {
    v1k0 = v1kc * v1ts / v1ti;
  }
  v1k1 = v1kc * v1td / v1ts;
  v1lpf1 = (2.0 * v1k_lpf - v1ts) / (2.0 * v1k_lpf + v1ts);
  v1lpf2 = v1ts / (2.0 * v1k_lpf + v1ts);
}

void update_pid_1() {
  double v1ek;
  double v1lpf;
  v1ek = target_temp_1 - temp_1;
  if (vrg1){
    v1pp = v1kc * (v1xk_1 - temp_1);
    v1pi = v1k0 * v1ek;
    v1pd = v1k1 * (2.0 * v1xk_1 - temp_1 - v1xk_2);
    heat_1_speed += v1pp + v1pi + v1pd;
  }
  else { 
    heat_1_speed = v1pp = v1pi = v1pd = 0.0; 
  }
  v1xk_2 = v1xk_1;
  v1xk_1 = temp_1;
  if (heat_1_speed > GMA_HLIM) {
    heat_1_speed = GMA_HLIM;
  }
  else if (heat_1_speed < GMA_LLIM) {
    heat_1_speed = GMA_LLIM;
  }
  analogWrite(heat_1, heat_1_speed);
} 
