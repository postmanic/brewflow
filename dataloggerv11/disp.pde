public void VisKnapper(){

   cp5 = new ControlP5(this);
   c = new ControlTimer();
   t = new Textlabel(cp5,"--",100,100);
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashInTemp")
     .setPosition(20,10)
     .setCaptionLabel("Mash In")
     .setSize(150,30)
     .setRange(10,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashStep1")
     .setPosition(20,49)
     .setCaptionLabel("Mash Step 1")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashStep2")
     .setPosition(20,80)
     .setCaptionLabel("Mash Step 2")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("MashStep3")
     .setPosition(20,111)
     .setCaptionLabel("Mash Step 3")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;     
  
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 

  cp5.addSlider("MashOutTemp")
     .setPosition(20,150)
     .setCaptionLabel("Mash Out")
     .setSize(150,30)
     .setRange(40,90)
     .setSliderMode(Slider.FLEXIBLE)
     ;

  cp5.addSlider("PumpSpeed")
     .setPosition(260,10)
     .setCaptionLabel("Pump")
     .setSize(150,30)
     .setRange(0,100)
     .setSliderMode(Slider.FLEXIBLE)
     ; 

  //cp5.addButton("StartMashIn")
     //.setValue(0)
     //.setPosition(175,10)
     //.setCaptionLabel("GO")
     //.setSize(25,30)
     //.getCaptionLabel().align(CENTER,CENTER)
     //;  
 
  cp5.addButton("ReadyReceived")
     .setValue(0)
     .setPosition(20,185)
     .setCaptionLabel("GO")
     .setSize(40,20)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
     
  // create a new button with name 'buttonA'
  cp5.addButton("StartPump")
     .setValue(0)
     .setPosition(260,45)
     .setCaptionLabel("Run")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;     

  // create a new button with name 'buttonA'
  cp5.addButton("StopPump")
     .setValue(0)
     .setPosition(305,45)
     .setCaptionLabel("Stop")
     .setSize(40,15)
     .getCaptionLabel().align(CENTER,CENTER)
     ;

 
  cp5.getController("MashInTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("MashStep1").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0); 
  cp5.getController("MashStep2").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MashStep3").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("MashOutTemp").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
  cp5.getController("PumpSpeed").getCaptionLabel().align(ControlP5.CENTER, ControlP5.LEFT_OUTSIDE).setPaddingX(0);
   
  
}



void StartPump() {
String pump1Speed = str((int)PumpSpeed);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);

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

void StopPump() {
String pump1Speed = str((int)0);
  myPort.write("9020");
  myPort.write(pump1Speed);
  myPort.write(lf);
 
}
