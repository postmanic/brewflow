
void update_pump(){
  if (wspeed1 > 100) {
    wspeed1 = 100;
  }
  if (wspeed1 > 0) {
    pumpspeed = (wspeed1 * 255) / 100;
  }
    
  if (pumpstate == 1) {    
    digitalWrite(pump1ctrl, LOW);    
    analogWrite(pump1pwm, pumpspeed);
  }
  else {
    digitalWrite(pump1ctrl, LOW);
    analogWrite(pump1pwm, 0);

  } 
}
