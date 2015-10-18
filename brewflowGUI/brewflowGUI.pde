   
   void setup() {
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
      
    t.setPosition(200, 160);
     t.setValue(c.toString());
     t.draw(this);

   
 }
