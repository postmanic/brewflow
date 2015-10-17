

   Graph MyArduinoGraph = new Graph(630,410,320,279,color (200,20,20));


Slider abc;
   void setup() {
      img = loadImage("tank.png");
      size(1024, 768); 
      createGUI();
      VisKnapper();
      TidsLinje = new float[0]; 
      DynamicArray3= new float[0];
      DynamicArray2= new float[0];
      BarArray3= new float[0];
      MyArduinoGraph.xLabel="Time (m)";
      MyArduinoGraph.yLabel="Temperatur (t)";
      MyArduinoGraph.Title=" brewpot session ";  
      //noLoop();
      PortSelected=1;      /* ====================================================================
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
   /* ====================================================================
       Time3 & Voltage3 are arrays sent by the chip (any size)look in the
       switch(Command) statement if you're interested.
       DataRecieved3 is made true when the chip confirms that the 
       array has finished being sent
      ====================================================================  */
   
   if( DataRecieved3 ){
      MyArduinoGraph.yMin=0;      
      MyArduinoGraph.yMax=90;
      MyArduinoGraph.xMax=180;
      MyArduinoGraph.DrawAxis();
      MyArduinoGraph.GraphColor=color(200,40,40);    
      MyArduinoGraph.smoothLine(Time3,Voltage3);
      MyArduinoGraph.GraphColor=color(0,0,255);         
      MyArduinoGraph.smoothLine(Time3,Voltage2);
   }
 }

