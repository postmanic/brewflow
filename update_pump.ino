
void update_pump(){
  if (wspeed1 > 100) {
    wspeed1 = 100;
  }
  if (wspeed1 > 0) {
    pump_speed = (wspeed1 * 255) / 100;
  }
    
  if (pump1state == 1) {    
    digitalWrite(pump_control, LOW);    
    analogWrite(pump_pwm, pump_speed);
  }
  else {
    digitalWrite(pump_control, LOW);
    analogWrite(pump_pwm, 0);

  } 
}
