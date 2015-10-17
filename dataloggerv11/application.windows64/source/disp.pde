public void VisKnapper(){

cp5 = new ControlP5(this);
  MashStep1Timer = new ControlTimer();
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

  cp5.addButton("StartMashIn")
     .setValue(0)
     .setPosition(175,10)
     .setCaptionLabel("GO")
     .setSize(25,30)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
 
  cp5.addButton("StartMash")
     .setValue(0)
     .setPosition(20,185)
     .setCaptionLabel("Start")
     .setSize(40,20)
     .getCaptionLabel().align(CENTER,CENTER)
     ;  
     
  // create a new button with name 'buttonA'
  cp5.addButton("StartPump")
     .setValue(0)
     .setPosition(260,45)
     .setCaptionLabel("Start")
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
  myPort.write("p1");
  myPort.write(pump1Speed);
  myPort.write(lf);

}


void StartMashIn() {
  myPort.write("mash1");
  myPort.write(lf);
}

void StopPump() {
String pump1Speed = str((int)0);
  myPort.write("p1");
  myPort.write(pump1Speed);
  myPort.write(lf);
 
}
