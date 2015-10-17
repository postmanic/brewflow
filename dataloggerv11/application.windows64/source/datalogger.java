import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import g4p_controls.*; 
import controlP5.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class datalogger extends PApplet {



   Graph MyArduinoGraph = new Graph(630,410,320,279,color (200,20,20));


Slider abc;
   public void setup() {
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


    public void draw() {
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



public void StartPump() {
String pump1Speed = str((int)PumpSpeed);
  myPort.write("p1");
  myPort.write(pump1Speed);
  myPort.write(lf);

}


public void StartMashIn() {
  myPort.write("mash1");
  myPort.write(lf);
}

public void StopPump() {
String pump1Speed = str((int)0);
  myPort.write("p1");
  myPort.write(pump1Speed);
  myPort.write(lf);
 
}
/*   =================================================================================       
     The Graph class contains functions and variables that have been created to draw 
     graphs. Here is a quick list of functions within the graph class:
          
       Graph(int x, int y, int w, int h,color k)
       DrawAxis()
       Bar([])
       smoothLine([][])
       DotGraph([][])
       LineGraph([][]) 
     
     =================================================================================*/   

    
    class Graph 
    {
      
      boolean Dot=true;            // Draw dots at each data point if true
      boolean RightAxis;            // Draw the next graph using the right axis if true
      boolean ErrorFlag=false;      // If the time array isn't in ascending order, make true  
      boolean ShowMouseLines=true;  // Draw lines and give values of the mouse position
    
      int     xDiv=5,yDiv=5;            // Number of sub divisions
      int     xPos,yPos;            // location of the top left corner of the graph  
      int     Width,Height;         // Width and height of the graph
    

      int   GraphColor;
      int   BackgroundColor=color(255);  
      int   StrokeColor=color(180);     
      
      String  Title="Title";          // Default titles
      String  xLabel="x - Label";
      String  yLabel="y - Label";

      float   yMax=1024, yMin=0;      // Default axis dimensions
      float   xMax=10, xMin=0;
      float   yMaxRight=1024,yMinRight=0;
  
      PFont   Font;                   // Selected font used for text 
      
  //    int Peakcounter=0,nPeakcounter=0;
     
      Graph(int x, int y, int w, int h,int k) {  // The main declaration function
        xPos = x;
        yPos = y;
        Width = w;
        Height = h;
        GraphColor = k;
        
      }
    
     
       public void DrawAxis(){
       
   /*  =========================================================================================
        Main axes Lines, Graph Labels, Graph Background
       ==========================================================================================  */
    
        fill(BackgroundColor); color(0);stroke(StrokeColor);strokeWeight(1);
        int t=60;
        
        rect(xPos-t*1.6f,yPos-t,Width+t*2.5f,Height+t*2);            // outline
        textAlign(CENTER);textSize(18);
        float c=textWidth(Title);
        fill(BackgroundColor); color(0);stroke(0);strokeWeight(1);
        rect(xPos+Width/2-c/2,yPos-35,c,0);                         // Heading Rectangle  
        
        fill(0);
        text(Title,xPos+Width/2,yPos-37);                            // Heading Title
        textAlign(CENTER);textSize(14);
        text(xLabel,xPos+Width/2,yPos+Height+t/1.5f);                     // x-axis Label 
        
        rotate(-PI/2);                                               // rotate -90 degrees
        text(yLabel,-yPos-Height/2,xPos-t*1.6f+20);                   // y-axis Label  
        rotate(PI/2);                                                // rotate back
        
        textSize(10); noFill(); stroke(0); smooth();strokeWeight(1);
          //Edges
          line(xPos-3,yPos+Height,xPos-3,yPos);                        // y-axis line 
          line(xPos-3,yPos+Height,xPos+Width+5,yPos+Height);           // x-axis line 
          
           stroke(200);
          if(yMin<0){
                    line(xPos-7,                                       // zero line 
                         yPos+Height-(abs(yMin)/(yMax-yMin))*Height,   // 
                         xPos+Width,
                         yPos+Height-(abs(yMin)/(yMax-yMin))*Height
                         );
          
                    
          }
          
          if(RightAxis){                                       // Right-axis line   
              stroke(0);
              line(xPos+Width+3,yPos+Height,xPos+Width+3,yPos);
            }
            
           /*  =========================================================================================
                Sub-devisions for both axes, left and right
               ==========================================================================================  */
            
            stroke(0);
            
           for(int x=0; x<=xDiv; x++){
       
            /*  =========================================================================================
                  x-axis
                ==========================================================================================  */
             
            line(PApplet.parseFloat(x)/xDiv*Width+xPos-3,yPos+Height,       //  x-axis Sub devisions    
                 PApplet.parseFloat(x)/xDiv*Width+xPos-3,yPos+Height+5);     
                 
            textSize(10);                                      // x-axis Labels
            String xAxis=str(xMin+PApplet.parseFloat(x)/xDiv*(xMax-xMin));  // the only way to get a specific number of decimals 
            String[] xAxisMS=split(xAxis,'.');                 // is to split the float into strings 
            text(xAxisMS[0]+"."+xAxisMS[1].charAt(0),          // ...
                 PApplet.parseFloat(x)/xDiv*Width+xPos-3,yPos+Height+15);   // x-axis Labels
          }
          
          
           /*  =========================================================================================
                 left y-axis
               ==========================================================================================  */
          
          for(int y=0; y<=yDiv; y++){
            line(xPos-3,PApplet.parseFloat(y)/yDiv*Height+yPos,                // ...
                  xPos-7,PApplet.parseFloat(y)/yDiv*Height+yPos);              // y-axis lines 
            
            textAlign(RIGHT);fill(20);
            
            String yAxis=str(yMin+PApplet.parseFloat(y)/yDiv*(yMax-yMin));     // Make y Label a string
            String[] yAxisMS=split(yAxis,'.');                    // Split string
           
            text(yAxisMS[0]+"."+yAxisMS[1].charAt(0),             // ... 
                 xPos-15,PApplet.parseFloat(yDiv-y)/yDiv*Height+yPos+3);       // y-axis Labels 
                        
                        
            /*  =========================================================================================
                 right y-axis
                ==========================================================================================  */
            
            if(RightAxis){
             
              color(GraphColor); stroke(GraphColor);fill(20);
            
              line(xPos+Width+3,PApplet.parseFloat(y)/yDiv*Height+yPos,             // ...
                   xPos+Width+7,PApplet.parseFloat(y)/yDiv*Height+yPos);            // Right Y axis sub devisions
                   
              textAlign(LEFT); 
            
              String yAxisRight=str(yMinRight+PApplet.parseFloat(y)/                // ...
                                yDiv*(yMaxRight-yMinRight));           // convert axis values into string
              String[] yAxisRightMS=split(yAxisRight,'.');             // 
           
               text(yAxisRightMS[0]+"."+yAxisRightMS[1].charAt(0),     // Right Y axis text
                    xPos+Width+15,PApplet.parseFloat(yDiv-y)/yDiv*Height+yPos+3);   // it's x,y location
            
              noFill();
            }stroke(0);
            
          
          }
          
 
      }
      
      
   /*  =========================================================================================
       Bar graph
       ==========================================================================================  */   
      
      public void Bar(float[] a ,int from, int to) {
        
         
          stroke(GraphColor);
          fill(GraphColor);
          
          if(from<0){                                      // If the From or To value is out of bounds 
           for (int x=0; x<a.length; x++){                 // of the array, adjust them 
               rect(PApplet.parseInt(xPos+x*PApplet.parseFloat(Width)/(a.length)),
                    yPos+Height-2,
                    Width/a.length-2,
                    -a[x]/(yMax-yMin)*Height);
                 }
          }
          
          else {
          for (int x=from; x<to; x++){
            
            rect(PApplet.parseInt(xPos+(x-from)*PApplet.parseFloat(Width)/(to-from)),
                     yPos+Height-2,
                     Width/(to-from)-2,
                     -a[x]/(yMax-yMin)*Height);
                     
    
          }
          }
          
      }
  public void Bar(float[] a ) {
  
              stroke(GraphColor);
          fill(GraphColor);
    
  for (int x=0; x<a.length; x++){                 // of the array, adjust them 
               rect(PApplet.parseInt(xPos+x*PApplet.parseFloat(Width)/(a.length)),
                    yPos+Height-2,
                    Width/a.length-2,
                    -a[x]/(yMax-yMin)*Height);
                 }
          }
  
  
   /*  =========================================================================================
       Dot graph
       ==========================================================================================  */   
       
        public void DotGraph(float[] x ,float[] y) {
          
         for (int i=0; i<x.length; i++){
                    strokeWeight(2);stroke(GraphColor);noFill();smooth();
           ellipse(
                   xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width,
                   yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height,
                   2,2
                   );
         }
                             
      }
      
   /*  =========================================================================================
       Streight line graph 
       ==========================================================================================  */
       
      public void LineGraph(float[] x ,float[] y) {
          
         for (int i=0; i<(x.length-1); i++){
                    strokeWeight(2);stroke(GraphColor);noFill();smooth();
           line(xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width,
                                            yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height,
                                            xPos+(x[i+1]-x[0])/(x[x.length-1]-x[0])*Width,
                                            yPos+Height-(y[i+1]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height);
         }
                             
      }
      
      /*  =========================================================================================
             smoothLine
          ==========================================================================================  */
    
      public void smoothLine(float[] x ,float[] y) {
         
        float tempyMax=yMax, tempyMin=yMin;
        
        if(RightAxis){yMax=yMaxRight;yMin=yMinRight;} 
         
        int counter=0;
        int xlocation=0,ylocation=0;
         
//         if(!ErrorFlag |true ){    // sort out later!
          
          beginShape(); strokeWeight(2);stroke(GraphColor);noFill();smooth();
         
            for (int i=0; i<x.length; i++){
              
           /* ===========================================================================
               Check for errors-> Make sure time array doesn't decrease (go back in time) 
              ===========================================================================*/
              if(i<x.length-1){
                if(x[i]>x[i+1]){
                   
                  ErrorFlag=true;
                
                }
              }
         
         /* =================================================================================       
             First and last bits can't be part of the curve, no points before first bit, 
             none after last bit. So a streight line is drawn instead   
            ================================================================================= */ 

              if(i==0 || i==x.length-2)line(xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width,
                                            yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height,
                                            xPos+(x[i+1]-x[0])/(x[x.length-1]-x[0])*Width,
                                            yPos+Height-(y[i+1]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height);
                                            
          /* =================================================================================       
              For the rest of the array a curve (spline curve) can be created making the graph 
              smooth.     
             ================================================================================= */ 
                            
              curveVertex( xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width,
                           yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height);
                           
           /* =================================================================================       
              If the Dot option is true, Place a dot at each data point.  
             ================================================================================= */    
           
             if(Dot)ellipse(
                             xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width,
                             yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height,
                             2,2
                             );
                             
         /* =================================================================================       
             Highlights points closest to Mouse X position   
            =================================================================================*/ 
                          
              if( abs(mouseX-(xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width))<5 ){
                
                 
                  float yLinePosition = yPos+Height-(y[i]/(yMax-yMin)*Height)+(yMin)/(yMax-yMin)*Height;
                  float xLinePosition = xPos+(x[i]-x[0])/(x[x.length-1]-x[0])*Width;
                  strokeWeight(1);stroke(240);
                 // line(xPos,yLinePosition,xPos+Width,yLinePosition);
                  strokeWeight(2);stroke(GraphColor);
                  
                  ellipse(xLinePosition,yLinePosition,4,4);
              }
              
     
              
            }  
       
          endShape(); 
          yMax=tempyMax; yMin=tempyMin;
                float xAxisTitleWidth=textWidth(str(map(xlocation,xPos,xPos+Width,x[0],x[x.length-1])));
          
           
       if((mouseX>xPos&mouseX<(xPos+Width))&(mouseY>yPos&mouseY<(yPos+Height))){   
        if(ShowMouseLines){
              // if(mouseX<xPos)xlocation=xPos;
            if(mouseX>xPos+Width)xlocation=xPos+Width;
            else xlocation=mouseX;
            stroke(200); strokeWeight(0.5f);fill(255);color(50);
            // Rectangle and x position
            line(xlocation,yPos,xlocation,yPos+Height);
            rect(xlocation-xAxisTitleWidth/2-10,yPos+Height-16,xAxisTitleWidth+20,12);
            
            textAlign(CENTER); fill(160);
            text(map(xlocation,xPos,xPos+Width,x[0],x[x.length-1]),xlocation,yPos+Height-6);
            
           // if(mouseY<yPos)ylocation=yPos;
             if(mouseY>yPos+Height)ylocation=yPos+Height;
            else ylocation=mouseY;
          
           // Rectangle and y position
            stroke(200); strokeWeight(0.5f);fill(255);color(50);
            
            line(xPos,ylocation,xPos+Width,ylocation);
             int yAxisTitleWidth=PApplet.parseInt(textWidth(str(map(ylocation,yPos,yPos+Height,y[0],y[y.length-1]))) );
            rect(xPos-15+3,ylocation-6, -60 ,12);
            
            textAlign(RIGHT); fill(GraphColor);//StrokeColor
          //    text(map(ylocation,yPos+Height,yPos,yMin,yMax),xPos+Width+3,yPos+Height+4);
            text(map(ylocation,yPos+Height,yPos,yMin,yMax),xPos -15,ylocation+4);
           if(RightAxis){ 
                          
                           stroke(200); strokeWeight(0.5f);fill(255);color(50);
                           
                           rect(xPos+Width+15-3,ylocation-6, 60 ,12);  
                            textAlign(LEFT); fill(160);
                           text(map(ylocation,yPos+Height,yPos,yMinRight,yMaxRight),xPos+Width+15,ylocation+4);
           }
            noStroke();noFill();
         }
       }
            
   
      }

       
          public void smoothLine(float[] x ,float[] y, float[] z, float[] a ) {
           GraphColor=color(188,53,53);
            smoothLine(x ,y);
           GraphColor=color(193-100,216-100,16);
           smoothLine(z ,a);
   
       }
       
       
       
    }
/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */



// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.CYAN_SCHEME);
  G4P.setCursor(ARROW);
  if(frame != null)
    frame.setTitle("sbp v1.0");

  label1 = new GLabel(this, 445, 535, 51, 38);
  label1.setText("Target");
  label1.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label1.setOpaque(true);
  label3 = new GLabel(this, 360, 440, 69, 38);
  label3.setText("NA");
  label3.setTextBold();
  label3.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label3.setOpaque(true);
  label4 = new GLabel(this, 106, 635, 70, 38);
  label4.setText("NA");
  label4.setTextBold();
  label4.setLocalColorScheme(GCScheme.RED_SCHEME);
  label4.setOpaque(true);
  label5 = new GLabel(this, 358, 635, 70, 38);
  label5.setText("NA");
  label5.setTextBold();
  label5.setLocalColorScheme(GCScheme.RED_SCHEME);
  label5.setOpaque(true);
  label7 = new GLabel(this, 106, 440, 70, 38);
  label7.setText("NA");
  label7.setTextBold();
  label7.setLocalColorScheme(GCScheme.BLUE_SCHEME);
  label7.setOpaque(true);
  
 
}

// Variable declarations 
// autogenerated do not edit
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
GToggleGroup togGroup1; 
GToggleGroup togGroup2; 
GOption option1; 
GOption option2; 
GOption option3; 

   
   
      
 
 
   PImage img;
   PGraphics pg;
   ControlP5 cp5;
   Textlabel t;
   ControlTimer MashStep1Timer, MashStep2Timer, MashStep3Timer;
   int MashInTemp = 59, MashStep1 = 50, MashStep2 = 66, MashStep3 = 72, MashOutTemp = 78, PumpSpeed = 0;  
   int ventmedatsendedata;
   int SerialPortNumber=1;
   int PortSelected=1;
   int lf = 10, val;   
/*   =================================================================================       
     Global variables
     =================================================================================*/
     

   boolean Error=true;
   int mlttemp;
   boolean UpdateGraph=true;
   int lineGraph; 
   int ErrorCounter=0;
   int TotalRecieved=0; 
 
/*   =================================================================================       
     Local variables
     =================================================================================*/
   boolean DataRecieved1=false,DataRecieved2=false,DataRecieved3=false;

   float[] DynamicArrayTime1,DynamicArrayTime2,TidsLinje;
   float[] Time1,Time2,Time3, Bar3; 
   float[] Voltage1,Voltage2,Voltage3;
   float[] current;
   float[] DynamicArray1,DynamicArray2,DynamicArray3,BarArray3;
          
   float[] PowerArray= new float[0];            // Dynamic arrays that will use the append()
   float[] DynamicArrayPower = new float[0];    // function to add values
   float[] DynamicArrayTime= new float[0];
    
   String portName; 
   String[] ArrayOfPorts=new String[SerialPortNumber]; 

   boolean DataRecieved=false,Data1Recieved=false,Data2Recieved=false;
   int incrament=0;

   int NumOfSerialBytes=8;                              // The size of the buffer array
   int[] serialInArray = new int[NumOfSerialBytes];     // Buffer array
   int serialCount = 0;                                 // A count of how many bytes received
   int xMSB, xLSB,yMSB, yLSB, zMSB, zLSB;                    // Bytes of data

  Serial myPort;                                        // The serial port object


/*   =================================================================================       
      A once off serail port setup function. In this case the selection of the speed,
      the serial port and clearing the serial port buffer  
     =================================================================================*/

public void SerialPortSetup(){
   
   text(Serial.list().length,200,200);
   
   portName= Serial.list()[PortSelected];
   println( Serial.list());
   ArrayOfPorts=Serial.list();
   println(ArrayOfPorts);
   myPort = new Serial(this, "COM3", 57600);
   delay(50);
   myPort.clear(); 
}

  /* ============================================================    
      serialEvent will be called when something is sent to the 
      serial port being used. 
     ============================================================   */

public void serialEvent(Serial myPort) {


  /* ============================================================    
      Read the next byte that's waiting in the buffer. 
     ============================================================   */
 
    String myString = myPort.readStringUntil(lf);
    print(myString);
    String myArray[] = split(myString, ',');
    int command = PApplet.parseInt(myArray[0]);

switch(command) {

  
/*  ==================================================================
      Recieve temperature and time from chip, update graph      
    ==================================================================  */
    
    case 1010: // Status
     
     float mlttemp = PApplet.parseInt(myArray[1]);
     float hlttemp = PApplet.parseInt(myArray[2]);         
     float targettemp = PApplet.parseInt(myArray[2]); 
     float myticks = PApplet.parseInt(myArray[2]);    
     
          TidsLinje=append( TidsLinje, (60 / 60) );
          DynamicArray3=append( DynamicArray3, mlttemp);
          DynamicArray2=append( DynamicArray2, ((hlttemp / 10)) ); //hlttemp
          BarArray3=append( BarArray3, targettemp / 10 ); //targettemp




          Time3=TidsLinje;
          Voltage3=DynamicArray3;
          Voltage2=DynamicArray2;
          Bar3=BarArray3;
          DataRecieved3=true;
          
    break;




   }
   
      
   redraw(); 
 
 
 }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "datalogger" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
