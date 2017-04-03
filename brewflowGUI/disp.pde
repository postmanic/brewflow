
import controlP5.*; 

ControlP5 cp5;

int MashInTemp = 73;
int Step1Temp = 67;
int Step2Temp;
int Step3Temp;
int Step4Temp;
int MashOutTemp = 76;
int BoilTemp = 101;

int MashInTimer;
int Step1Timer = 60;
int Step2RiseTimer;
int Step2Timer;
int Step3RiseTimer;
int Step3Timer;
int Step4RiseTimer;
int Step4Timer;
int MashOutRiseTimer;
int MashOutTimer = 10;
int BoilTimer = 90;

public void VisKnapper() {

  cp5 = new ControlP5(this);

  cp5.addSlider("MashInTemp")
    .setPosition(15, 56)
    .setCaptionLabel("Mash In")
    .setSize(150, 30)
    .setRange(10, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("Step1Temp")
    .setPosition(15, 89)
    .setCaptionLabel("Step 1 TEMP")
    .setSize(150, 30)
    .setRange(40, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("Step2Temp")
    .setPosition(15, 120)
    .setCaptionLabel("Step 2 TEMP")
    .setSize(150, 30)
    .setRange(40, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("Step3Temp")
    .setPosition(15, 151)
    .setCaptionLabel("Step 3 TEMP")
    .setSize(150, 30)
    .setRange(40, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;     

  cp5.addSlider("Step4Temp")
    .setPosition(15, 182)
    .setCaptionLabel("Step 4 TEMP")
    .setSize(150, 30)
    .setRange(40, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;   

  cp5.addSlider("MashOutTemp")
    .setPosition(15, 215)
    .setCaptionLabel("Mash Out")
    .setSize(150, 30)
    .setRange(40, 90)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("BoilTemp")
    .setPosition(15, 248)
    .setCaptionLabel("Boil TEMP")
    .setSize(150, 30)
    .setRange(95, 105)
    .setSliderMode(Slider.FLEXIBLE)
    ;     

  cp5.addSlider("Step1Timer")
    .setPosition(180, 89)
    .setCaptionLabel("Step 1 Timer")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ;


  cp5.addSlider("Step2Timer")
    .setPosition(180, 120)
    .setCaptionLabel("Step 2 Timer")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("Step3Timer")
    .setPosition(180, 151)
    .setCaptionLabel("Step 3 Timer")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("Step4Timer")
    .setPosition(180, 182)
    .setCaptionLabel("Step 4 Timer")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ;

  cp5.addSlider("BoilTimer")
    .setPosition(180, 248)
    .setCaptionLabel("Boil Timer")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ;


  cp5.addSlider("PumpSpeed1")
    .setPosition(410, 200)
    .setCaptionLabel("DEBUG")
    .setSize(150, 30)
    .setRange(0, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ; 

  cp5.addSlider("PumpSpeed2")
    .setPosition(410, 125)
    .setCaptionLabel("PUMP SPEED")
    .setSize(150, 30)
    .setRange(20, 100)
    .setSliderMode(Slider.FLEXIBLE)
    ; 


  cp5.addButton("SetReceipe")
    .setValue(0)
    .setPosition(15, 283)
    .setCaptionLabel("Add")
    .setSize(40, 20)
    .getCaptionLabel().align(CENTER, CENTER)
    ;  

  // create a new button with name 'buttonA'
   cp5.addButton("StartPump")
      .setValue(0)
     .setPosition(454,159)
     .setCaptionLabel("Start")
     .setSize(40,15)
    .getCaptionLabel().align(CENTER,CENTER)
    ;     

   //create a new button with name 'buttonA'
   cp5.addButton("StopPump")
    .setValue(0)
    .setPosition(499,159)
    .setCaptionLabel("Stop")
    .setSize(40,15)
    .getCaptionLabel().align(CENTER,CENTER)
    ;

  cp5.addButton("SetPump")
    .setValue(0)
    .setPosition(410, 159)
    .setCaptionLabel("Set")
    .setSize(40, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;     

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
    .setPosition(410, 235)
    .setCaptionLabel("Adjust")
    .setSize(40, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;     

  // create a new button with name 'buttonA'
  cp5.addButton("Mlock")
    .setValue(0)
    .setPosition(610, 167)
    .setCaptionLabel("MALT ADDED")
    .setSize(80, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;

  // create a new button with name 'buttonA'
  cp5.addButton("Ilock")
    .setValue(0)
    .setPosition(610, 150)
    .setCaptionLabel("WATER ADDED")
    .setSize(80, 15)
    .getCaptionLabel().align(CENTER, CENTER)
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
    .setPosition(712, 240)
    .setCaptionLabel("Reset Controller")
    .setSize(79, 25)
    .getCaptionLabel().align(CENTER, CENTER)
    ;

  cp5.addButton("SteepSetting")
    .setValue(0)
    .setPosition(610, 184)
    .setCaptionLabel("MASHOUT DONE")
    .setSize(80, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;

  cp5.addButton("TempSetting")
    .setValue(0)
    .setPosition(610, 201)
    .setCaptionLabel("TEMP SENSING")
    .setSize(80, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;


  // create a new button with name 'buttonA'
  cp5.addButton("DebugT1")
    .setValue(0)
    .setPosition(410, 235)
    .setCaptionLabel("T1")
    .setSize(40, 15)
    .getCaptionLabel().align(CENTER, CENTER)
    ;  

  // create a new button with name 'buttonA'
  cp5.addButton("DebugT2")
    .setValue(0)
    .setPosition(454, 235)
    .setCaptionLabel("T2")
    .setSize(40, 15)
    .getCaptionLabel().align(CENTER, CENTER)
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
  String mlock = "1";
  myPort.write("9041");
  myPort.write(mlock);
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
  String debugt1 = str(PumpSpeed1*100);
  myPort.write("2010");
  myPort.write(debugt1);
  myPort.write(lf);
}

public void DebugT2() {
  String debugt2 = str(PumpSpeed1*100);
  myPort.write("2020");
  myPort.write(debugt2);
  myPort.write(lf);
}

// Event stop pump has been pressed. Event stops when pump stop
// is received from Arduino.

public void SetReceipe() {
  receipe = 1;
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
  delay(400);

  myPort.write("9011");
  myPort.write(step1temp);
  myPort.write(lf);
  delay(400);

  myPort.write("9012");
  myPort.write(step2temp);
  myPort.write(lf);
  delay(400);

  myPort.write("9013");
  myPort.write(step3temp);
  myPort.write(lf);
  delay(400);

  myPort.write("9014");
  myPort.write(step4temp);
  myPort.write(lf);
  delay(400);

  myPort.write("9015");
  myPort.write(mashouttemp);
  myPort.write(lf);
  delay(400);

  myPort.write("9016");
  myPort.write(boiltemp);
  myPort.write(lf);
  delay(400);

  myPort.write("9021");
  myPort.write(step1timer);
  myPort.write(lf);
  delay(400);

  myPort.write("9022");
  myPort.write(step2timer);
  myPort.write(lf);
  delay(400); 

  myPort.write("9023");
  myPort.write(step3timer);
  myPort.write(lf);
  delay(400);

  myPort.write("9024");
  myPort.write(step4timer);
  myPort.write(lf);
  delay(400);

  myPort.write("9025");
  myPort.write(boiltimer);
  myPort.write(lf);
  delay(400);
}

public void StopPump() {
  String pumpspeed = "0";
  myPort.write("9090");
  myPort.write(pumpspeed);
  myPort.write(lf);
  delay(400);
}

public void StartPump() {
  String pumpspeed = str((int)PumpSpeed2);
  myPort.write("9090");
  myPort.write(pumpspeed);
  myPort.write(lf);
  delay(400);
}

public void SetPump() {
  String pumpspeed = str((int)PumpSpeed2);
  myPort.write("9090");
  myPort.write(pumpspeed);
  myPort.write(lf);
  delay(400);
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