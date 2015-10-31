
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

  // Ticker
  label13 = new GLabel(this,10, 270, 385, 36);
  label13.setText("Waiting");
  label13.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  label13.setOpaque(true);
 
}

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

