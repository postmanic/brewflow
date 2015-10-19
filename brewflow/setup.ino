void setup() { 
  init_pid_1();
  init_pid_2();
  sensors.begin();
  delay(2);
  wdt_enable(WDTO_8S);
  int temp_sens = (sensors.getDeviceCount(), DEC);
  
  analogReference(EXTERNAL);
  
  pinMode(heat_1, OUTPUT);
  pinMode(heat_2, OUTPUT); 
  pinMode(pump_1_ctrl, OUTPUT);
  pinMode(pump_2_ctrl, OUTPUT);
  pinMode(pump_3_ctrl, OUTPUT);
  digitalWrite(pump_1_ctrl, HIGH);
  digitalWrite(pump_2_ctrl, HIGH);
  digitalWrite(pump_3_ctrl, HIGH); 
  analogWrite(heat_1, LOW);
  analogWrite(heat_2, LOW); 
  
  Serial.begin(57600);
}
