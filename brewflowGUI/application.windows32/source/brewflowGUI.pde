   
   void setup() {
      img = loadImage("tank.png");
      size(800, 800); 
      createGUI();
      VisKnapper();
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

     //if (int (dogwatch+7000) < millis()){    
     //dogWatch();
     //dogwatch = millis();
     //}
 }