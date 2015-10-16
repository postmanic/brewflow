void init_pid() {
  ts_ticks = (int)((ts * 1000.0) / T_50MSEC);
  if (ts_ticks > TWENTY_SECONDS) {
    ts_ticks = TWENTY_SECONDS;
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

void Opdater_PID() {
  double ek;
  double lpf;
  ek = target_temp_1 - temp_1;
  if (vrg){
    pp = kc * (xk_1 - temp_1);
    pi = k0 * ek;
    pd = k1 * (2.0 * xk_1 - temp_1 - xk_2);
    heat_1_speed += pp + pi + pd;
  }
  else { 
    heat_1_speed = pp = pi = pd = 0.0; 
  }
  xk_2 = xk_1;
  xk_1 = temp_1;
  if (heat_1_speed > GMA_HLIM) {
    heat_1_speed = GMA_HLIM;
  }
  else if (heat_1_speed < GMA_LLIM) {
    heat_1_speed = GMA_LLIM;
  }
  analogWrite(heat_1, heat_1_speed);
} 
