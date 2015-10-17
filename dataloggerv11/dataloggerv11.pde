   
   void setup() {
      img = loadImage("tank.png");
      ControlTimer c;
      
      
      
      size(1024, 768); 
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
      fill(0,0,0);
      rect(15,5,238,205);
      fill(0,0,0);
      rect(255,5,160,205);
      image(img,10,350,510,410);

      t.setValue("00:00:00");
      t.draw(this);
      t.setPosition(200, 20);
      t.setValue("00:00:00");
      t.draw(this);
      t.setPosition(200, 60);
      t.setValue("00:00:00");
      t.draw(this);
      t.setPosition(200, 90);
      t.setValue("00:00:00");
      t.draw(this);
      t.setPosition(200, 120);
      t.setValue("00:00:00");
      t.draw(this);
      
      t.setPosition(200, 160);
      t.setValue(c.toString());
      t.draw(this);

   
 }

