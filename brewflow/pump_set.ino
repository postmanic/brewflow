

void pump_set(int wpump, int wspeed){
  
    if (wspeed > 100) {
      wspeed = 100;
    }
    if (wspeed > 0) {
      
    pumpspeed[wpump] = wspeed * 255 / 100;

    //Serial.println(test);
    
    analogWrite(pump[wpump], wspeed);
    pumpstate[wpump] = HIGH;
    }
    else {
    analogWrite(pump[wpump], 0);
    pumpspeed[wpump] = 0;
    pumpstate[wpump] = LOW;
    } 
}
