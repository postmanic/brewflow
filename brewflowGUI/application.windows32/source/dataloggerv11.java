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

public class dataloggerv11 extends PApplet {

   
   public void setup() {
      img = loadImage("tank.png");
      ControlTimer c;
      
      
      
      size(800, 800); 
      createGUI();
      VisKnapper();
      int PortSelected=1;      /* ====================================================================
                              adjust this (0,1,2...) until the correct port is selected 
                              In my case 2 for COM4, after I look at the Serial.list() string 
                              println( Serial.list() );
                              [0] "COM1"  
                              [1] "COM2" 
                              [2] "COM4"
                             ==================================================================== */
      SerialPortSetup();      // speed of 115200 bps etc.
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

      //t.setValue("");
      //t.draw(this);
     // t.setPosition(200, 20);
     // t.setValue("00:00:00");
     // t.draw(this);
     // t.setPosition(200, 60);
     // t.setValue("00:00:00");
     // t.draw(this);
     // t.setPosition(200, 90);
     // t.setValue("00:00:00");
     // t.draw(this);
     // t.setPosition(200, 120);
    //  t.setValue("00:00:00");
     // t.draw(this);
      
    t.setPosition(200, 160);
     t.setValue(c.toString());
     t.draw(this);

   
 }

public void VisKnapper(){

   cp5 = new ControlP5(this);

   c = new ControlTimer();
   t = new Textlabel(cp5,"--",100,100);

  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashInTemp")
     .setPosition(15,50)
     .setCaptionLabel("Mash In")
     .setSize(150,30)
     .setRange(10,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  
  cp5.addSlider("MashStep1")
     .setPosition(15,89)
     .setCaptionLabel("Mash Step 1")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashStep2")
     .setPosition(15,120)
     .setCaptionLabel("Mash Step 2")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashStep3")
     .setPosition(15,151)
     .setCaptionLabel("Mash Step 3")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;     
  
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 

  cp5.addSlider("MashOutTemp")
     .setPosition(15,190)
     .setCaptionLabel("Mash Out")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
     
  cp5.addSlider("MLTSetTemp")
     .setPosition(610,105)
     .setCaptionLabel("Set Temp MLT")
     .setSize(150,30)
     .setRange(20,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

     
  cp5.addSlider("HLTSetTemp")
     .setPosition(610,50)
     .setCaptionLabel("Set Temp HLT")
     .setSize(150,30)
     .setRange(20,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("FERSetTemp")
     .setPosition(610,160)
     .setCaptionLabel("Set Temp FERMENTOR")
     .setSize(150,30)
     .setRange(0,40)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("PumpSpeed1")
     .setPosition(410,50)
     .setCaptionLabel("Pump HLT")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ; 

  cp5.addSlider("PumpSpeed2")
     .setPosition(410,105)
     .setCaptionLabel("Pump MLT")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ; 

  cp5.addSlider("PumpSpeed3")
     .setPosition(410,160)
     .setCaptionLabel("Pump HERMS")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ; 
 
  cp5.addButton("ReadyReceived")
     .setValue(0)
     .setPosition(15,225)
     .setCaptionLabel("GO")
     .setSize(40,20)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
     
  // create a new button with name 'buttonA'
  cp5.addButton("StartPump1")
     .setValue(0)
     .setPosition(410,85)
     .setCaptionLabel("Run")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;     

  // create a new button with name 'buttonA'
  cp5.addButton("StopPump1")
     .setValue(0)
     .setPosition(454,85)
     .setCaptionLabel("Stop")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

  cp5.addButton("StartPump2")
     .setValue(0)
     .setPosition(410,140)
     .setCaptionLabel("Run")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;     

  // create a new button with name 'buttonA'
  cp5.addButton("StopPump2")
     .setValue(0)
     .setPosition(454,140)
     .setCaptionLabel("Stop")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
  // create a new button with name 'buttonA'
  cp5.addButton("StartPump3")
     .setValue(0)
     .setPosition(410,195)
     .setCaptionLabel("Run")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;     

  // create a new button with name 'buttonA'
  cp5.addButton("StopPump3")
     .setValue(0)
     .setPosition(454,195)
     .setCaptionLabel("Stop")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
     
  // create a new button with name 'buttonA'
  cp5.addButton("SetHLTTemp")
     .setValue(0)
     .setPosition(610,85)
     .setCaptionLabel("Set")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
 
   // create a new button with name 'buttonA'
  cp5.addButton("StopHLTTemp")
     .setValue(0)
     .setPosition(652,85)
     .setCaptionLabel("Off")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

   // create a new button with name 'buttonA'
  cp5.addButton("BoilHLTTemp")
     .setValue(0)
     .setPosition(720,85)
     .setCaptionLabel("Boil")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;
     
  // create a new button with name 'buttonA'
  cp5.addButton("SetMLTTemp")
     .setValue(0)
     .setPosition(610,140)
     .setCaptionLabel("Set")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

  cp5.addButton("StopMLTTemp")
     .setValue(0)
     .setPosition(652,140)
     .setCaptionLabel("Off")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

  cp5.addButton("BoilMLTTemp")
     .setValue(0)
     .setPosition(720,140)
     .setCaptionLabel("Boil")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

  // create a new button with name 'buttonA'
  cp5.addButton("SetFerTemp")
     .setValue(0)
     .setPosition(610,195)
     .setCaptionLabel("Set")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  

  // create a new button with name 'buttonA'
  cp5.addButton("StopFerTemp")
     .setValue(0)
     .setPosition(652,195)
     .setCaptionLabel("Off")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
 
  cp5.getController("MashInTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("MashStep1").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("MashStep2").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MashStep3").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MashOutTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MLTSetTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("HLTSetTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("FERSetTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("PumpSpeed1").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("PumpSpeed2").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("PumpSpeed3").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
}

public void ReadyReceived() {
  
  mashstep++;
    
  switch(mashstep)
    {
    case 1:
     label13.setText("Waiting for GO!");    
    break;
    
    case 2:
     label13.setText("Add water to MLT");    
    break;
    
    case 3:
     label13.setText("Heating water to "+MashInTemp+"\u00b0");
      myPort.write("9010"); 
      myPort.write(str(MashInTemp));
      myPort.write(lf);
      
    break;
    
    case 4:
     // msg received from Arduino. temperature reached.
     label13.setText("Add grain to MLT");        
    break;
    
    case 5:
     label13.setText("Step 1, timer running.");        
    break;
    
    case 6:
     // Timer done
     label13.setText("Heating to "+MashInTemp);
     // Send msg to Arduino. Heat to preset temp.     
    break;    
     
    case 7:
     // msg received from Arduino. temperature reached.
     label13.setText("Step 2, timer running.");
 
    break;     
    
    case 8:
     // Timer done
     label13.setText("Heating to "+MashInTemp);
     // Send msg to Arduino. Heat to preset temp.     
    break;      
    
     case 9:
     // msg received from Arduino. temperature reached.
     label13.setText("Step 3, timer running.");    
    break;     
    }
  
  
}

public void StartPump1() {
String pump1Speed = str((int)PumpSpeed1);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);

}

public void StopPump1() {
String pump1Speed = str((int)0);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);
 
}

public void StartPump2() {
String pump2Speed = str((int)PumpSpeed2);
  myPort.write("9030");
  myPort.write(pump2Speed);
  myPort.write(lf);

}

public void StopPump2() {
String pump2Speed = str((int)0);
  myPort.write("9030");
  myPort.write(pump2Speed);
  myPort.write(lf);
}

public void StartPump3() {
String pump3Speed = str((int)PumpSpeed3);
  myPort.write("9040");
  myPort.write(pump3Speed);
  myPort.write(lf);

}

public void StopPump3() {
String pump3Speed = str((int)0);
  myPort.write("9040");
  myPort.write(pump3Speed);
  myPort.write(lf);
 
}

public void SetHLTTemp() {
String HLTtemp = str((int)HLTSetTemp);
  myPort.write("9050");
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

public void StopMLTTemp() {
String MLTtemp = str((int)MLTSetTemp);
  myPort.write("9080");
  myPort.write(0);
  myPort.write(lf);

}


/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */



// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.CYAN_SCHEME);
  G4P.setCursor(ARROW);
  if(frame != null)
    frame.setTitle("brewflow v1.1");

  label1 = new GLabel(this, 536, 480, 60, 18);
  label1.setText("...");
  label1.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label1.setOpaque(true);

  // Target HLT
  label2 = new GLabel(this, 286, 480, 60, 18);
  label2.setText("...");
  label2.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label2.setOpaque(true);
  
  // Target HLT
  label14 = new GLabel(this, 213, 480, 71, 18);
  label14.setText("SET TEMP");
  //label14.setLocalColorScheme(GCScheme.BLACK_SCHEME);
  label14.setOpaque(true);
  
  // Temp 1 readout MLT
  label3 = new GLabel(this, 536, 440, 60, 18);
  label3.setText("...");
  label3.setTextBold();
  label3.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label3.setOpaque(true);
  
  // Temp 1 label MLT
  label18 = new GLabel(this, 463, 440, 71, 18);
  label18.setText("TEMP 1");
  //label16.setLocalColorScheme(GCScheme.RED_SCHEME);
  label18.setOpaque(true);   
  
  
  // Temp 2 reaout MLT
  label6 = new GLabel(this, 536, 460, 60, 18);
  label6.setText("...");
  label6.setTextBold();
  label6.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label6.setOpaque(true);
  
  // Temp 2 label MLT
  label17 = new GLabel(this, 463, 460, 71, 18);
  label17.setText("TEMP 2");
  //label16.setLocalColorScheme(GCScheme.RED_SCHEME);
  label17.setOpaque(true); 

  // Target 2 label MLT
  label19 = new GLabel(this, 463, 480, 71, 18);
  label19.setText("SET TEMP");
  label19.setOpaque(true);


  
  // Heater 1 readout HLT
  label4 = new GLabel(this, 286, 625, 60, 18);
  label4.setText("...");
  label4.setTextBold();
  label4.setLocalColorScheme(GCScheme.RED_SCHEME);
  label4.setOpaque(true);
 
  // Heater 1 label HLT
  label23 = new GLabel(this, 213, 625, 71, 18);
  label23.setText("HEATER 1");
  //label23.setTextBold();
  //label23.setLocalColorScheme(GCScheme.RED_SCHEME);
  label23.setOpaque(true);
 
  
  // Heater 2 readout MLT
  label5 = new GLabel(this, 536, 625, 60, 18);
  label5.setText("...");
  label5.setTextBold();
  label5.setLocalColorScheme(GCScheme.RED_SCHEME);
  label5.setOpaque(true);
 
  // Heater 2 label MLT
  label22 = new GLabel(this, 463, 625, 71, 18);
  label22.setText("HEATER 2");
  //label5.setTextBold();
  //label5.setLocalColorScheme(GCScheme.RED_SCHEME);
  label22.setOpaque(true);
 
  
  
  // Temp 1 readout HLT
  label7 = new GLabel(this, 286, 440, 60, 18);
  label7.setText("...");
  label7.setTextBold();
  label7.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label7.setOpaque(true);
  
  // Temp 1 label HLT
  label15 = new GLabel(this, 213, 440, 71, 18);
  label15.setText("TEMP 1");
  //label15.setLocalColorScheme(GCScheme.RED_SCHEME);
  label15.setOpaque(true); 
  
  // Temp 2 readout HLT
  label8 = new GLabel(this, 286, 460, 60, 18);
  label8.setText("...");
  label8.setTextBold();
  label8.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label8.setOpaque(true);
  
  // Temp 2 label HLT
  label16 = new GLabel(this, 213, 460, 71, 18);
  label16.setText("TEMP 2");
  //label16.setLocalColorScheme(GCScheme.RED_SCHEME);
  label16.setOpaque(true); 
  
  label9 = new GLabel(this, 15, 10, 120, 18);
  label9.setText("AUTOMASH");
  //label9.setLocalColorScheme(GCScheme.RED_SCHEME);
  label9.setOpaque(true);

  label10 = new GLabel(this, 410, 10, 120, 18);
  label10.setText("SYSTEM CONTROL");
  //label10.setLocalColorScheme(GCScheme.RED_SCHEME);
  label10.setOpaque(true);


  // Pump 2 readout MLT
  label12 = new GLabel(this, 536, 604, 60, 18);
  label12.setText("...");
  label12.setLocalColorScheme(GCScheme.CYAN_SCHEME);
  label12.setOpaque(true);
  
  
  // Pump 1 readout HLT
  label11 = new GLabel(this, 286, 604, 60, 18);
  label11.setText("...");
  label11.setLocalColorScheme(GCScheme.CYAN_SCHEME);
  label11.setOpaque(true);
  
  // Pump 1 label HLT
  label21 = new GLabel(this, 213, 604, 71, 18);
  label21.setText("PUMP 1");
  label21.setOpaque(true);
  
  // Pump 2 label MLT
  label20 = new GLabel(this, 463, 604, 71, 18);
  label20.setText("PUMP 2");
  label20.setOpaque(true);

  label13 = new GLabel(this,10, 270, 385, 36);
  label13.setText("Waiting");
  label13.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  label13.setOpaque(true);

 
}

// Variable declarations 
// autogenerated do not edit
GSlider slider1; 
GLabel label2; 
GLabel label1; 
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
   ControlTimer c, MashStep1Timer, MashStep2Timer, MashStep3Timer;
   int HLTSetTemp = 70, MLTSetTemp = 70, FERSetTemp = 20, MashInTemp = 59, MashStep1 = 50, MashStep2 = 66, MashStep3 = 72, MashOutTemp = 78, PumpSpeed1 = 0, PumpSpeed2 = 0, PumpSpeed3 = 0;  
   int lf = 10, val;  
   int mashstep = 0;
/*   =================================================================================       
     Global variables
     =================================================================================*/
  Serial myPort;                                        // The serial port object


public void SerialPortSetup(){
   myPort = new Serial(this, "COM3", 57600);
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
      
      
      
      
      float temp_1 = PApplet.parseFloat(myArray[2])/10; 
      float temp_2 = PApplet.parseFloat(myArray[3])/10; 
      float temp_3 = PApplet.parseFloat(myArray[4])/10;    
      float temp_4 = PApplet.parseFloat(myArray[5])/10; 
      int target_temp_1 = PApplet.parseInt(myArray[8]);      
      int target_temp_2 = PApplet.parseInt(myArray[9]);
      int heat_1 = PApplet.parseInt(myArray[14])*20;
      int heat_2 = PApplet.parseInt(myArray[15])*20;      
      
      int vrg1 = PApplet.parseInt(myArray[21]);      
      if (vrg1 > 0){
         label4.setLocalColorScheme(GCScheme.RED_SCHEME);  
      }
      else
      {
         label4.setLocalColorScheme(GCScheme.CYAN_SCHEME);
      }
     
      int vrg2 = PApplet.parseInt(myArray[22]);
      if (vrg2 > 0){
         label5.setLocalColorScheme(GCScheme.RED_SCHEME);  
      }
      else
      {
         label5.setLocalColorScheme(GCScheme.CYAN_SCHEME);
      }      
      float pump_1_speed = (PApplet.parseFloat(myArray[16])/255)*100;
      if (pump_1_speed > 0){
         label11.setLocalColorScheme(GCScheme.RED_SCHEME);
      }
      else
      {
      label11.setLocalColorScheme(GCScheme.CYAN_SCHEME);  
      }
      float pump_2_speed = (PApplet.parseFloat(myArray[17])/255)*100;
            if (pump_2_speed > 0){
         label12.setLocalColorScheme(GCScheme.RED_SCHEME);
      }
      else
      {
      label12.setLocalColorScheme(GCScheme.CYAN_SCHEME);  
      }
      float pump_3_speed = (PApplet.parseFloat(myArray[18])/255)*100;      
     
      
      //float pump_3_speed = (float(myArray[17])/255)*100;
      label2.setText(str(target_temp_1)+"\u00b0"); // pot 1 temp 1
      label1.setText(str(target_temp_2)+"\u00b0"); // pot 1 temp 1
      label3.setText(str(temp_3)+"\u00b0");        // pot 1 temp 1
      label4.setText(str(heat_1)+" W");   //HLT heater
      label5.setText(str(heat_2)+" W");   //MLT heater
      label6.setText(str(temp_2)+"\u00b0");        // pot 1 temp 2     
      label7.setText(str(temp_1)+"\u00b0");        // pot 1 temp 1
      label8.setText(str(temp_4)+"\u00b0");        // pot 1 temp 1
      label11.setText(str(PApplet.parseInt(pump_1_speed))+"%"); //Pumpe 1 hastighed 
      label12.setText(str(PApplet.parseInt(pump_2_speed))+"%"); //Pumpe 2 hastighed      
    break;
    }
  }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "dataloggerv11" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
