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
  v2ek = target_temp_2 - temp_2;
  if (vrg2){
    v2pp = v2kc * (v2xk_1 - temp_2);
    v2pi = v2k0 * v2ek;
    v2pd = v2k1 * (2.0 * v2xk_1 - temp_2 - v2xk_2);
    heat_2_speed += v2pp + v2pi + v2pd;
  }
  else { 
    heat_2_speed = v2pp = v2pi = v2pd = 0.0; 
  }
  v2xk_2 = v2xk_1;
  v2xk_1 = temp_2;
  if (heat_2_speed > GMA_HLIM) {
    heat_2_speed = GMA_HLIM;
  }
  else if (heat_2_speed < GMA_LLIM) {
    heat_2_speed = GMA_LLIM;
  }
  analogWrite(heat_2, heat_2_speed);
} 
