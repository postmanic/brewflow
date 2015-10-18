   import processing.serial.*;
   import g4p_controls.*;
   import controlP5.*;   
 
   PImage img;
   PGraphics pg;
   ControlP5 cp5;
   Textlabel t;
   ControlTimer c, MashStep1Timer, MashStep2Timer, MashStep3Timer;
   int HLTSetTemp = 70, MLTSetTemp = 70, FERSetTemp = 20, MashInTemp = 59, MashStep1 = 50, MashStep2 = 66, MashStep3 = 72, MashOutTemp = 78, PumpSpeed1 = 0, PumpSpeed2 = 0, PumpSpeed3 = 0;  
   int lf = 10, val;  
   int mashstep = 0;
/*   =================================================================================       
     Global variables
     =================================================================================*/
  Serial myPort;                                        // The serial port object


void SerialPortSetup(){
   myPort = new Serial(this, "COM3", 57600);
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
    
      float temp_1 = float(myArray[2])/10; 
      float temp_2 = float(myArray[3])/10; 
      float temp_3 = float(myArray[4])/10;    
      float temp_4 = float(myArray[5])/10; 
      int target_temp_1 = int(myArray[8]);      
      int target_temp_2 = int(myArray[10]);
      int heat_1 = int(myArray[15])*20;     
      int heat_2 = int(myArray[14])*20; 
      float pump_1_speed = (float(myArray[16])/255)*100;
      float pump_2_speed = (float(myArray[17])/255)*100;
      //float pump_3_speed = (float(myArray[17])/255)*100;
      label1.setText(str(target_temp_1)+"°"); // pot 1 temp 1
      label2.setText(str(target_temp_2)+"°"); // pot 1 temp 1
      label3.setText(str(temp_1)+"°");        // pot 1 temp 1
      label4.setText(str(heat_1)+" W");   //HLT heater
      label5.setText(str(heat_2)+" W");   //MLT heater
      label6.setText(str(temp_2)+"°");        // pot 1 temp 2     
      label7.setText(str(temp_3)+"°");        // pot 1 temp 1
      label8.setText(str(temp_4)+"°");        // pot 1 temp 1
      label11.setText(str(int(pump_1_speed))+"%"); //Pumpe 1 hastighed 
      label12.setText(str(int(pump_2_speed))+"%"); //Pumpe 2 hastighed      
    break;
    }
  }
