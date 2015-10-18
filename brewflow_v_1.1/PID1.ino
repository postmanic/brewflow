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
