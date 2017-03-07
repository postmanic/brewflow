   

  
   void setup() {
      img = loadImage("tank.png");
      size(800, 800); 
      createGUI();
      VisKnapper();
      SerialPortSetup();
      myPort.bufferUntil(lf);

} 

    void draw() {
   

      stroke(153);
      fill(0,0,0);
      rect(5,5,393,305);
      fill(0,0,0);     
      rect(402,5,393,305);      

     // image(img,150,350,510,410);
      
   //   stroke(153);
   //   fill(0,0,0);
   //   rect(210,437,138,63);      

      //stroke(153);
      //fill(0,0,0);
      //rect(5,312,138,63);  
      // stroke(153);
     //fill(0,0,0);
     // rect(145,312,138,45);
      
      
     // stroke(153);
    //  fill(0,0,0);
    //  rect(210,600,138, 45);      


     //if (int (dogwatch+7000) < millis()){    
     //dogWatch();
     //dogwatch = millis();
     //}
     
       // Draw the first plot
       if (millis() >= 5000){
  plot1.beginDraw();
  plot1.drawBox();
  plot1.drawXAxis();
  plot1.drawYAxis();
  plot1.drawTitle();
  plot1.drawPoints();
  plot1.drawLines();
  plot1.endDraw();
 
  // Change the second plot vertical scale from Celsius to Kelvin
  plot2.setYLim(celsiusToKelvin(plot1.getYLim()));
 
  // Draw only the right axis
  plot2.beginDraw();
  plot2.drawRightAxis();
  plot2.endDraw();}
 }