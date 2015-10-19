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

void ReadyReceived() {
  
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
     label13.setText("Heating water to "+MashInTemp+"°");
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

void StartPump1() {
String pump1Speed = str((int)PumpSpeed1);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);

}

void StopPump1() {
String pump1Speed = str((int)0);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);
 
}

void StartPump2() {
String pump2Speed = str((int)PumpSpeed2);
  myPort.write("9030");
  myPort.write(pump2Speed);
  myPort.write(lf);

}

void StopPump2() {
String pump2Speed = str((int)0);
  myPort.write("9030");
  myPort.write(pump2Speed);
  myPort.write(lf);
}

void StartPump3() {
String pump3Speed = str((int)PumpSpeed3);
  myPort.write("9040");
  myPort.write(pump3Speed);
  myPort.write(lf);

}

void StopPump3() {
String pump3Speed = str((int)0);
  myPort.write("9040");
  myPort.write(pump3Speed);
  myPort.write(lf);
 
}

void SetHLTTemp() {
String HLTtemp = str((int)HLTSetTemp);
  myPort.write("9010");
  myPort.write(HLTtemp);
  myPort.write(lf);

}

void StopHLTTemp() {
String HLTtemp = str((int)HLTSetTemp);
  myPort.write("9060");
  myPort.write(0);
  myPort.write(lf);

}


void SetMLTTemp() {
String MLTtemp = str((int)MLTSetTemp);
  myPort.write("9070");
  myPort.write(MLTtemp);
  myPort.write(lf);

}

void StopMLTTemp() {
String MLTtemp = str((int)MLTSetTemp);
  myPort.write("9080");
  myPort.write(0);
  myPort.write(lf);

}

void dogWatch() {
  myPort.write("1111");
  myPort.write(lf);
}
