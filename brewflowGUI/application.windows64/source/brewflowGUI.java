import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import g4p_controls.*; 
import controlP5.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class brewflowGUI extends PApplet {

   
   public void setup() {
      img = loadImage("tank.png");
       
      createGUI();
      VisKnapper();
      SerialPortSetup();
      myPort.bufferUntil(lf);
  }

    public void draw() {
      background(255);
      stroke(153);
      fill(0,0,0);
      rect(5,5,393,305);
      
      
      fill(0,0,0);     
      rect(402,5,393,305);      

      image(img,150,350,510,410);
      
      stroke(153);
      fill(0,0,0);
      rect(210,437,138,63);      

      stroke(153);
      fill(0,0,0);
      rect(460,437,138,63);  
      
      stroke(153);
      fill(0,0,0);
      rect(210,600,138, 45);      

      stroke(153);
      fill(0,0,0);
      rect(460,600,138,45);  

     //if (int (dogwatch+7000) < millis()){    
     //dogWatch();
     //dogwatch = millis();
     //}
 }
public void VisKnapper(){

   cp5 = new ControlP5(this);

  cp5.addSlider("MashInTemp")
     .setPosition(15,56)
     .setCaptionLabel("Mash In")
     .setSize(150,30)
     .setRange(10,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
  
  cp5.addSlider("Step1Temp")
     .setPosition(15,89)
     .setCaptionLabel("Step 1 TEMP")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("Step2Temp")
     .setPosition(15,120)
     .setCaptionLabel("Step 2 TEMP")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("Step3Temp")
     .setPosition(15,151)
     .setCaptionLabel("Step 3 TEMP")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;     

  cp5.addSlider("Step4Temp")
     .setPosition(15,182)
     .setCaptionLabel("Step 4 TEMP")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;   

  cp5.addSlider("MashOutTemp")
     .setPosition(15,215)
     .setCaptionLabel("Mash Out")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
 
   cp5.addSlider("BoilTemp")
     .setPosition(15,248)
     .setCaptionLabel("Boil TEMP")
     .setSize(150,30)
     .setRange(95,105)
     .setSliderMode(Slider.FLEXIBLE)
     ;     
     
  cp5.addSlider("Step1Timer")
     .setPosition(180,89)
     .setCaptionLabel("Step 1 Timer")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ;

     
  cp5.addSlider("Step2Timer")
     .setPosition(180,120)
     .setCaptionLabel("Step 2 Timer")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("Step3Timer")
     .setPosition(180,151)
     .setCaptionLabel("Step 3 Timer")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("Step4Timer")
     .setPosition(180,182)
     .setCaptionLabel("Step 4 Timer")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("BoilTimer")
     .setPosition(180,248)
     .setCaptionLabel("Boil Timer")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ;


  cp5.addSlider("PumpSpeed1")
     .setPosition(410,50)
     .setCaptionLabel("DEBUG")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ; 

  cp5.addSlider("PumpSpeed2")
     .setPosition(410,225)
     .setCaptionLabel("BOIL TEMP")
     .setSize(150,30)
     .setRange(95,105)
     .setSliderMode(Slider.FLEXIBLE)
     ; 

 
  cp5.addButton("SetReceipe")
     .setValue(0)
     .setPosition(15,283)
     .setCaptionLabel("Add")
     .setSize(40,20)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
     
  // create a new button with name 'buttonA'
 // cp5.addButton("StartPump1")
 //    .setValue(0)
  //   .setPosition(410,185)
  //   .setCaptionLabel("Run")
  //   .setSize(40,15)
   //  .getCaptionLabel().align(CENTER,CENTER)
   //  ;     

  // create a new button with name 'buttonA'
 // cp5.addButton("StopPump1")
   //  .setValue(0)
   //  .setPosition(454,185)
   //  .setCaptionLabel("Stop")
   //  .setSize(40,15)
   //  .getCaptionLabel().align(CENTER,CENTER)
   //  ;

 // cp5.addButton("StartPump2")
   //  .setValue(0)
   //  .setPosition(410,140)
   //  .setCaptionLabel("Run")
   //  .setSize(40,15)
   //  .getCaptionLabel().align(CENTER,CENTER)
  //   ;     

  // create a new button with name 'buttonA'
 // cp5.addButton("StopPump2")
    // .setValue(0)
    // .setPosition(454,140)
    // .setCaptionLabel("Stop")
   //  .setSize(40,15)
   //  .getCaptionLabel().align(CENTER,CENTER)
   //  ;
  // create a new button with name 'buttonA'
  cp5.addButton("StartPump3")
     .setValue(0)
     .setPosition(410,260)
     .setCaptionLabel("Adjust")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;     

  // create a new button with name 'buttonA'
  cp5.addButton("Mlock")
     .setValue(0)
     .setPosition(610,67)
     .setCaptionLabel("MALT ADDED")
     .setSize(80,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
     
  // create a new button with name 'buttonA'
  cp5.addButton("Ilock")
     .setValue(0)
     .setPosition(610,50)
     .setCaptionLabel("WATER ADDED")
     .setSize(80,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
 
   // create a new button with name 'buttonA'
  //cp5.addButton("StartMash")
     //.setValue(0)
     //.setPosition(610,84)
     //.setCaptionLabel("Start Brewing")
     //.setSize(80,15)
     //.getCaptionLabel().align(CENTER,CENTER)
     //;

   // create a new button with name 'buttonA'
  //cp5.addButton("BoilHLTTemp")
     //.setValue(0)
     //.setPosition(720,85)
     //.setCaptionLabel("Boil")
     //.setSize(40,15)
     //.getCaptionLabel().align(CENTER,CENTER)
     //;
     
  // create a new button with name 'buttonA'
  //cp5.addButton("SetMLTTemp")
     //.setValue(0)
     //.setPosition(610,140)
     //.setCaptionLabel("Set")
     //.setSize(40,15)
     //.getCaptionLabel().align(CENTER,CENTER)
     //;

  cp5.addButton("ResetController")
     .setValue(0)
     .setPosition(712,280)
     .setCaptionLabel("Reset Controller")
     .setSize(79,25)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

  //cp5.addButton("BoilMLTTemp")
     //.setValue(0)
     //.setPosition(720,140)
     //.setCaptionLabel("...")
     //.setSize(40,15)
     //.getCaptionLabel().align(CENTER,CENTER)
    // ;

  // create a new button with name 'buttonA'
  cp5.addButton("DebugT1")
     .setValue(0)
     .setPosition(410,85)
     .setCaptionLabel("T1")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  

  // create a new button with name 'buttonA'
  cp5.addButton("DebugT2")
     .setValue(0)
     .setPosition(454,85)
     .setCaptionLabel("T2")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
 
  cp5.getController("MashInTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("Step1Temp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("Step2Temp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("Step3Temp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("Step4Temp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MashOutTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("BoilTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
   
  cp5.getController("Step1Timer").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("Step2Timer").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("Step3Timer").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("Step4Timer").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("BoilTimer").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("PumpSpeed1").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("PumpSpeed2").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);

}

public void Ilock() {
String ilock = "1";
  myPort.write("9041");
  myPort.write(ilock);
  myPort.write(lf);
  delay(200);
}

public void Mlock() {
String mlock = "2";
  myPort.write("9042");
  myPort.write(mlock);
  myPort.write(lf);
  delay(200); 
}

public void StartMash() {

  myPort.write("9050");
  myPort.write(lf);
  delay(200); 
}

public void DebugT1() {
String debugt1 = str((int)PumpSpeed1);
  myPort.write("2010");
  myPort.write(debugt1);
  myPort.write(lf);
}

public void DebugT2() {
String debugt2 = str((int)PumpSpeed1);
  myPort.write("2020");
  myPort.write(debugt2);
  myPort.write(lf);

}

// Event stop pump has been pressed. Event stops when pump stop
// is received from Arduino.

public void SetReceipe() {

String mashintemp = str((int)MashInTemp);
String step1temp = str((int)Step1Temp);
String step2temp = str((int)Step2Temp);
String step3temp = str((int)Step3Temp);
String step4temp = str((int)Step4Temp);
String mashouttemp = str((int)MashOutTemp);
String boiltemp = str((int)BoilTemp);
String step1timer = str((int)Step1Timer);
String step2timer = str((int)Step2Timer);
String step3timer = str((int)Step3Timer);
String step4timer = str((int)Step4Timer);  
String boiltimer = str((int)BoilTimer);   
  
  myPort.write("9010");
  myPort.write(mashintemp);
  myPort.write(lf);
  delay(200);
  myPort.write("9011");
  myPort.write(step1temp);
  myPort.write(lf);
  delay(200);
  myPort.write("9012");
  myPort.write(step2temp);
  myPort.write(lf);
  delay(200);
  myPort.write("9013");
  myPort.write(step3temp);
  myPort.write(lf);
 delay(200); 
  myPort.write("9014");
  myPort.write(step4temp);
  myPort.write(lf);
 delay(200); 
  myPort.write("9015");
  myPort.write(mashouttemp);
  myPort.write(lf);
 delay(200);
  myPort.write("9016");
  myPort.write(boiltemp);
  myPort.write(lf);
 delay(200);
  myPort.write("9021");
  myPort.write(step1timer);
  myPort.write(lf);
 delay(200);  
  myPort.write("9022");
  myPort.write(step2timer);
  myPort.write(lf);
 delay(200);  
   myPort.write("9023");
  myPort.write(step3timer);
  myPort.write(lf);
 delay(200); 
   myPort.write("9024");
  myPort.write(step4timer);
  myPort.write(lf);
 delay(200); 
    myPort.write("9025");
  myPort.write(boiltimer);
  myPort.write(lf);
 delay(200); 
}

public void HLTSetTemp() {
String HLTtemp = str((int)HLTSetTemp);
  myPort.write("2010");
  myPort.write(HLTtemp);
  myPort.write(lf);

}

public void StopHLTTemp() {
String HLTtemp = str((int)HLTSetTemp);
  myPort.write("9060");
  myPort.write(0);
  myPort.write(lf);

}


public void SetMLTTemp() {
String MLTtemp = str((int)MLTSetTemp);
  myPort.write("9070");
  myPort.write(MLTtemp);
  myPort.write(lf);

}

public void ResetController() {
  myPort.write("9999");
  myPort.write(0);
  myPort.write(lf);

}

//void dogWatch() {
//  myPort.write("1111");
//  myPort.write(lf);
//}

public void createGUI(){
  
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.CYAN_SCHEME);
  G4P.setCursor(ARROW);
  if(frame != null)
    frame.setTitle("brewflow v0.1");



  // SET TEMP HLT
  //label2 = new GLabel(this, 286, 480, 60, 18);
  //label2.setText("...");
  //label2.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  //label2.setOpaque(true);
 
  //TEMP 1 LABEL MLT
  label18 = new GLabel(this, 463, 440, 71, 18);
  label18.setText("TEMP 1");
  label18.setOpaque(true);   
  
  // TEMP 1 VALUE MLT
  label3 = new GLabel(this, 536, 440, 60, 18);
  label3.setText("waiting");
  label3.setOpaque(true);
  
  //TEMP 2 LABEL MLT
  label17 = new GLabel(this, 463, 460, 71, 18);
  label17.setText("TEMP 2");
  label17.setOpaque(true);
  
  // TEMP 2 VALUE MLT
  label6 = new GLabel(this, 536, 460, 60, 18);
  label6.setText("waiting");
  label6.setOpaque(true); 

  //Target 2 label MLT
  label19 = new GLabel(this, 463, 480, 71, 18);
  label19.setText("SET TEMP");
  label19.setOpaque(true);
  
  // SET TEMP VALUE MLT
  label1 = new GLabel(this, 536, 480, 60, 18);
  label1.setText("waiting");
  label1.setOpaque(true);

  // PUMP LABEL MLT
  label20 = new GLabel(this, 463, 604, 71, 18);
  label20.setText("PUMP");
  label20.setOpaque(true); 
  
  // PUMP SPEED MLT
  label12 = new GLabel(this, 536, 604, 60, 18);
  label12.setText("waiting");
  label12.setOpaque(true); 
  
  // HEATER LABEL MLT
  label22 = new GLabel(this, 463, 625, 71, 18);
  label22.setText("HEATER");
  label22.setOpaque(true);
 
  // HEATER VALUE MLT
  label5 = new GLabel(this, 536, 625, 60, 18);
  label5.setText("waiting");
  label5.setOpaque(true);
  
  //label14 = new GLabel(this, 213, 480, 71, 18);
  //label14.setText("SET TEMP");
  //label14.setLocalColorScheme(GCScheme.BLACK_SCHEME);
  //label14.setOpaque(true);
  
  // TEMP 2
  //label3 = new GLabel(this, 536, 440, 60, 18);
  //label3.setText("T1");
  //label3.setTextBold();
  //label3.setOpaque(true);
  
  //Temp 1 label MLT
  //label18 = new GLabel(this, 463, 440, 71, 18);
  //label18.setText("TEMP 1");
  //label16.setLocalColorScheme(GCScheme.RED_SCHEME);
  //label18.setOpaque(true);   
  
  
  // Temp 2 reaout MLT
  //label6 = new GLabel(this, 536, 460, 60, 18);
  //label6.setText("T2");
  //label6.setTextBold();
  //label6.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  //label6.setOpaque(true);
  
   //Temp 2 label MLT
  //label17 = new GLabel(this, 463, 460, 71, 18);
  //label17.setText("TEMP 2");
  //label17.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  //label17.setOpaque(true); 

  // Target 2 label MLT
  //label19 = new GLabel(this, 463, 480, 71, 18);
  //label19.setText("SET TEMP");
  //label19.setOpaque(true);


  
  // Heater 1 readout HLT
  //label4 = new GLabel(this, 286, 625, 60, 18);
  //label4.setText("...");
  //label4.setTextBold();
  //label4.setLocalColorScheme(GCScheme.RED_SCHEME);
  //label4.setOpaque(true);
 
  // Heater 1 label HLT
  //label23 = new GLabel(this, 213, 625, 71, 18);
  //label23.setText("HEATER 1");
  //label23.setTextBold();
  //label23.setLocalColorScheme(GCScheme.RED_SCHEME);
  //label23.setOpaque(true);
 
  
 
  
  
  // Temp 1 readout HLT
  //label7 = new GLabel(this, 286, 440, 60, 18);
  //label7.setText("...");
  //label7.setTextBold();
  //label7.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  //label7.setOpaque(true);
  
  // Temp 1 label HLT
  //label15 = new GLabel(this, 213, 440, 71, 18);
  //label15.setText("TEMP 1");
  //label15.setLocalColorScheme(GCScheme.RED_SCHEME);
  //label15.setOpaque(true); 
  
  // Temp 2 readout HLT
  //label8 = new GLabel(this, 286, 460, 60, 18);
  //label8.setText("...");
  //label8.setTextBold();
  //label8.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  //label8.setOpaque(true);
  
  // Temp 2 label HLT
  //label16 = new GLabel(this, 213, 460, 71, 18);
  //label16.setText("TEMP 2");
  //label16.setLocalColorScheme(GCScheme.RED_SCHEME);
  //label16.setOpaque(true); 
  
  label9 = new GLabel(this, 15, 10, 58, 18);
  label9.setText("RECEIPE");
  label9.setOpaque(true);

  label10 = new GLabel(this, 410, 10, 120, 18);
  label10.setText("SYSTEM CONTROL");
  label10.setOpaque(true);

  // Pump 1 readout HLT
  label11 = new GLabel(this, 700, 67, 22, 15);
  label11.setText("NO");
  label11.setLocalColorScheme(GCScheme.RED_SCHEME);
  label11.setOpaque(true);
  
  // Pump 1 label HLT
  label21 = new GLabel(this, 700, 50, 22, 15);
  label21.setText("NO");
  label21.setLocalColorScheme(GCScheme.RED_SCHEME);
  label21.setOpaque(true);
  
  // Pump 2 label MLT
  //label20 = new GLabel(this, 463, 604, 71, 18);
  //label20.setText("PUMP 2");
  //label20.setOpaque(true);

  // Ticker
  //label13 = new GLabel(this,10, 270, 385, 36);
  //label13.setText("Waiting");
  //label13.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  //label13.setOpaque(true);
 
}

GSlider slider1; 
GLabel label1;
GLabel label2; 
GLabel label3; 
GLabel label4; 
GLabel label5; 
GLabel label7; 
GSlider slider2; 
GSlider slider3; 
GSlider slider4; 
GSlider slider5; 
GSlider slider6; 
GKnob knob1; 
GKnob knob2; 
GKnob knob3; 
GKnob knob4; 
GKnob knob5; 
GLabel label6; 
GLabel label8; 
GLabel label9; 
GLabel label10; 
GLabel label11; 
GLabel label12; 
GLabel label13; 
GLabel label14; 
GLabel label15; 
GLabel label16; 
GLabel label17; 
GLabel label18; 
GLabel label19;
GLabel label20;
GLabel label21;
GLabel label22;
GLabel label23;
GToggleGroup togGroup1; 
GToggleGroup togGroup2; 
GOption option1; 
GOption option2; 
GOption option3; 
   
   

      
 
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


public void SerialPortSetup(){
   myPort = new Serial(this, "COM5", 57600);
   delay(50);
   myPort.clear();
}

  /* ============================================================    
      serialEvent will be called when something is sent to the 
      serial port being used. 
     ============================================================   */

public void serialEvent(Serial myPort) {

  String myString = myPort.readStringUntil(lf);
  print(myString);
  String myArray[] = split(myString, ',');
  int command = PApplet.parseInt(myArray[0]);

  switch(command)
    {
    case 1010:

      int temp      = PApplet.parseInt (myArray[2]);      
      int temp1     = PApplet.parseInt (myArray[3]); 
      int temp2     = PApplet.parseInt (myArray[4]); 
      int ilock     = PApplet.parseInt (myArray[5]);
      int mlock     = PApplet.parseInt (myArray[6]);
      int vrg       = PApplet.parseInt (myArray[7]);
      int intensity = PApplet.parseInt (myArray[8]);
      int pump1state = PApplet.parseInt (myArray[9]);
      int pump1speed = PApplet.parseInt (myArray[10]);
      int updatestatus = PApplet.parseInt (myArray[11]);

       if (vrg > 0){
         label5.setLocalColorScheme(GCScheme.RED_SCHEME);
         label5.setText(PApplet.parseInt(intensity)+"%");        
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
     
     
      label1.setText(str(temp)+"\u00b0");      
      label3.setText(str(temp1)+"\u00b0"); 
      label6.setText(str(temp2)+"\u00b0");   
    break;
    }
  }
  public void settings() {  size(800, 800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--stop-color=#cccccc", "brewflowGUI" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
