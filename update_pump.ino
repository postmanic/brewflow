
void update_pump(){
  if (wspeed1 > 100) {
    wspeed1 = 100;
  }
  if (wspeed1 > 0) {
    pumpspeed = (wspeed1 * 255) / 100;
  }
    
  if (pumpstate == 1) {    
    digitalWrite(pumpcontrol, LOW);    
    analogWrite(pumppwm, pumpspeed);
  }
  else {
    digitalWrite(pumpcontrol, LOW);
    analogWrite(pumppwm, 0);

  } 
}
