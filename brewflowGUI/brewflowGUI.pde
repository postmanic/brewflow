float[] beerArray = { 0 };
int PumpSpeed1 = 0;
int PumpSpeed2 = 0;
int PumpSpeed3 = 0;
float temp_0, temp_1, temp_2;
int updatestatus = 0, mashstep = 0, a = 0;
int dogwatch, linewatch;
PImage img;
PGraphics pg;
  
Textlabel t;
GPlot plot1, plot2;

void setup() {
  size(800, 800); 
  createGUI();
  VisKnapper();
  SerialPortSetup();
  myPort.bufferUntil(lf);
  createGRAF();
} 

void draw() {
  stroke(153);
  fill(0, 0, 0);
  rect(5, 5, 393, 305);
  fill(0, 0, 0);     
  rect(402, 5, 393, 305);   

  GPointsArray points = new GPointsArray(beerArray.length);
    for (int i = 0; i < beerArray.length; i++) {
      points.add(i, beerArray[i]);
    }
  plot1.setPoints(points);
    plot1.beginDraw(); 
    plot1.drawBox();
    plot1.drawXAxis();
    plot1.drawYAxis();
    plot1.drawTitle();
    plot1.drawPoints();
    plot1.drawLines();
    plot1.endDraw();

    
    
  }