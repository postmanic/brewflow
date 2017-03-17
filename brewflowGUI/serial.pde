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

void serialEvent(Serial myPort) {

  String myString = myPort.readStringUntil(lf);
  print(myString);
  String myArray[] = split(myString, ',');
  int command = int(myArray[0]);

  switch(command)
  {
    
  case 1010:
    
    // add reading to graf arrayList 
    
    temp1   = int (myArray[3]); 
    float temp2   = int (myArray[4]); 
    int ilock     = int (myArray[5]);
    int mlock     = int (myArray[6]);
    int vrg       = int (myArray[7]);
    int intensity = int (myArray[8]);
    int pump1state = int (myArray[9]);
    float pump1speed = int (myArray[10]);
    int step_x = int (myArray[11]);    
    int updatestatus = int (myArray[13]);
    int pidtarget = int (myArray[12]);

    label14.setText("Case "+int(step_x)+" "+updatestatus);

    if (vrg > 0) {
      label5.setLocalColorScheme(GCScheme.RED_SCHEME);
      label5.setText(int(intensity)+"%");
    } else {
      label5.setLocalColorScheme(GCScheme.BLUE_SCHEME);
      label5.setText("  OFF");
    }

    if (pump1state == 1) {
      label12.setLocalColorScheme(GCScheme.RED_SCHEME);
      label12.setText(str(pump1speed)+"%");
    } else {
      label12.setLocalColorScheme(GCScheme.BLUE_SCHEME);
      label12.setText("  OFF");
    }

    if (ilock == 1) {
      label21.setLocalColorScheme(GCScheme.GREEN_SCHEME);
      label21.setText("OK");
    } else {
      label21.setLocalColorScheme(GCScheme.RED_SCHEME);
      label21.setText("NO");
    }
    
    if (mlock == 1) {
      label11.setLocalColorScheme(GCScheme.GREEN_SCHEME);
      label11.setText("OK");
    } else {
      label11.setLocalColorScheme(GCScheme.RED_SCHEME);
      label11.setText("NO");
    }
    
    if (temp1/10 >= 0) {
      label18.setLocalColorScheme(GCScheme.GREEN_SCHEME);
    } else {
      label18.setLocalColorScheme(GCScheme.RED_SCHEME);
    }

    if (temp2/10 >= 0) {
      label17.setLocalColorScheme(GCScheme.GREEN_SCHEME);
    } else {
      label17.setLocalColorScheme(GCScheme.RED_SCHEME);
    }



    if  (step_x == 3) {   
      statustext = "PID is 'ON'. Target is 'Step 1' temperature @ " + pidtarget + "°C" + "Timer is running, time left ";
    }

    if  (step_x == 2) {   
      statustext = "'MashIn' temperature @ " + pidtarget + "°C is reached. Ready for MashIn. Add malt and continue.";
    }

    if  (step_x == 1) {   
      statustext = "PID is 'ON'. Target is 'MashIn' temperature @ " + pidtarget + "°C";
    
    }
   
    
    if (step_x == 0) { 
       
      statustext = "System is idle. PID is 'OFF'. Pump is 'OFF'. ";      
    
      if (ilock == 0) {
      statustext += "Waiting for water. ";
      }
      
      if (receipe == 0) {
      statustext += "Waiting for Receipe. ";
      }

    }
    
    
    label20.setText(statustext);     
    label1.setText(pidtarget+"°");      
    label3.setText(str(temp1/10)+"°"); 
    label6.setText(str(temp2/10)+"°");

    break;
  }
}