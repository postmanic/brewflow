
int receipe = 0;
import processing.serial.*;

Serial myPort; 

int lf = 10, val;
String statustext = "";
void SerialPortSetup() {

  myPort = new Serial(this, "COM5", 57600);
  delay(50);
  myPort.clear();


}

/* ============================================================    
 serialEvent will be called when something is sent to the 
 serial port being used. 
 ============================================================   */