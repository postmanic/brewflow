   import processing.serial.*;
   import g4p_controls.*;

   import controlP5.*;   
 
   PImage img;
   PGraphics pg;
   ControlP5 cp5;
   Textlabel t;
   ControlTimer c, d, MashStep1Timer, MashStep2Timer, MashStep3Timer;
   int HLTSetTemp, MLTSetTemp=70, FERSetTemp = 20, MashInTemp, Step1Temp, Step2Temp, Step3Temp, MashOutTemp, PumpSpeed1 = 0, PumpSpeed2 = 0, PumpSpeed3 = 0;  
   int Step1Timer,Step2Timer,Step3Timer;
   
   
   int lf = 10, val;  
   int mashstep = 0;
   int dogwatch, linewatch;
/*   =================================================================================       
     Global variables
     =================================================================================*/
  Serial myPort;                                        // The serial port object


void SerialPortSetup(){
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
    case 1030:
    
    String line1 = myArray[2];
    label13.setText(line1);
    break;  
    
    case 1010:

      float temp = float(myArray[1]);      
      float temp1 = float(myArray[2]); 
      float temp2 = float(myArray[3]); 
      float temp3 = float(myArray[4]);    
      float temp4 = float(myArray[5]);
      float pump1speed = float(myArray[10]);
      float intensity = float(myArray[8]);
      
      //int target_temp_1 = int(myArray[8]);      
      //int target_temp_2 = int(myArray[9]);
     // int heat_1 = int(myArray[14])*20;
      //int heat_2 = int(myArray[15])*20;      
      
     int vrg = int(myArray[7]);      
       if (vrg > 0){
         label5.setLocalColorScheme(GCScheme.RED_SCHEME);  
      }
      else
      {
         label5.setLocalColorScheme(GCScheme.BLUE_SCHEME);
      }
     
   //   int vrg2 = int(myArray[22]);
   //   if (vrg2 > 0){
   //      label5.setLocalColorScheme(GCScheme.RED_SCHEME);  
   //   }
   //   else
   //   {
  //       label5.setLocalColorScheme(GCScheme.CYAN_SCHEME);
   //   }      
      float pump1state = (float(myArray[9])/255)*100;
      if (pump1state > 0){
         label12.setLocalColorScheme(GCScheme.RED_SCHEME);
      }
      else
      {
      label12.setLocalColorScheme(GCScheme.CYAN_SCHEME);  
      }
   //   float pump_2_speed = (float(myArray[17])/255)*100;
   //         if (pump_2_speed > 0){
   //      label12.setLocalColorScheme(GCScheme.RED_SCHEME);
   //   }
   //   else
   //   {
   //   label12.setLocalColorScheme(GCScheme.CYAN_SCHEME);  
   //   }
   //   float pump_3_speed = (float(myArray[18])/255)*100;      
     
      
     // float pump1speed = (float(myArray[9])/255)*100;
      //label2.setText(str(target_temp_1)+"°"); // pot 1 temp 1
      //label1.setText(str(target_temp_2)+"°"); // pot 1 temp 1
      //label13.setText(str(line1));        // pot 1 temp 1
      //label4.setText(str(heat_1)+" W");   //HLT heater
      label5.setText(int(intensity)+"%");   //MLT heater
      label6.setText(str(temp3)+"°");        // pot 1 temp 2     
      label7.setText(str(temp1)+"°");        // pot 1 temp 1
      label3.setText(str(temp2)+"°");        // pot 1 temp 1
      //label11.setText(str(int(pump1speed))+"%"); //Pumpe 1 hastighed 
      label12.setText(str(int(pump1speed))+"%"); //Pumpe 2 hastighed      
    break;
    }
  }