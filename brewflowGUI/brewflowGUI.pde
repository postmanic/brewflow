   
   void setup() {
      img = loadImage("tank.png");
      ControlTimer c;
      ControlTimer d;
      
      size(800, 800); 
      createGUI();
      VisKnapper();
      int PortSelected=1;
      SerialPortSetup();
      myPort.bufferUntil(lf);
  }


    void draw() {
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
      
     t.setPosition(343, 10);
     t.setValue(c.toString());
     t.draw(this);

      if (mashstep == 5) {

     t.setPosition(243, 10);
     t.setValue(d.toString());
     t.draw(this);
      }
      
 if (mashstep == 5 ) {      
     if (int (linewatch+700) < millis()){  
          linewatch = millis();  
     label13.setLocalColorScheme(GCScheme.RED_SCHEME);
     } 
     else { 
     label13.setLocalColorScheme(GCScheme.GREEN_SCHEME); 
     }
 }

     if (int (dogwatch+7000) < millis()){    
     dogWatch();
     dogwatch = millis();
     }
 }

