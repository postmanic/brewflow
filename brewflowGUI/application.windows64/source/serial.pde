   import processing.serial.*;
   import g4p_controls.*;

   import controlP5.*;   
 
   PImage img;
   PGraphics pg;
   ControlP5 cp5;
   Textlabel t;

   int HLTSetTemp, MLTSetTemp=70, FERSetTemp = 20, MashInTemp, Step1Temp, Step2Temp, Step3Temp, Step4Temp, MashOutTemp, BoilTemp, PumpSpeed1 = 0, PumpSpeed2 = 0, PumpSpeed3 = 0;  
   int Step1Timer,Step2Timer,Step3Timer, Step4Timer, BoilTimer;
  
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
    case 1010:

      int temp      = int (myArray[2]);      
      int temp1     = int (myArray[3]); 
      int temp2     = int (myArray[4]); 
      int ilock     = int (myArray[5]);
      int mlock     = int (myArray[6]);
      int vrg       = int (myArray[7]);
      int intensity = int (myArray[8]);
      int pump1state = int (myArray[9]);
      int pump1speed = int (myArray[10]);
      int updatestatus = int (myArray[11]);

       if (vrg > 0){
         label5.setLocalColorScheme(GCScheme.RED_SCHEME);
         label5.setText(int(intensity)+"%");        
       }
       else {
         label5.setLocalColorScheme(GCScheme.BLUE_SCHEME);
         label5.setText("off");
       }
    
      if (pump1state == 1) {
         label12.setLocalColorScheme(GCScheme.RED_SCHEME);
         label12.setText(str(pump1speed/255*100)+"%"); 
      }
      else {
        label12.setLocalColorScheme(GCScheme.BLUE_SCHEME);
        label12.setText("off");        
      }
      
      if (ilock == 1) {
         label21.setLocalColorScheme(GCScheme.GREEN_SCHEME);
         label21.setText("OK");
       }
       else {
         label21.setLocalColorScheme(GCScheme.RED_SCHEME);
         label21.setText("NO");         
       }
       
      if (mlock == 1) {
         label11.setLocalColorScheme(GCScheme.GREEN_SCHEME);
         label11.setText("OK");
       }
       else {
         label11.setLocalColorScheme(GCScheme.RED_SCHEME);
         label11.setText("NO");         
       }
     
     
      label1.setText(str(temp)+"°");      
      label3.setText(str(temp1)+"°"); 
      label6.setText(str(temp2)+"°");   
    break;
    }
  }