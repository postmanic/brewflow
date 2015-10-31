/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
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

