float[] beerArray1 = { 0 };
float[] beerArray2 = { 0 };
float[] beerArray3 = { 0 };
float PumpSpeed1 = 0;
int PumpSpeed2 = 0;
int PumpSpeed3 = 0;
float temp_0, temp_1, temp_2;
int updatestatus = 0, mashstep = 0, a = 0, pidtarget = 0;
int yk = 0, ilock = 0, mlock = 0, vrg = 0, pumpstate = 0, pumpspeed = 0, step_x = 0, pidtimer = 0; 
  
  
  
GPlot plot1, plot2, plot3;

void setup() {
  size(800, 800);

  createGUI();
  VisKnapper();
  SerialPortSetup();
  myPort.bufferUntil(lf);
  createGRAF();
} 

void draw() {

  background(255);
  stroke(253);
  fill(0, 0, 0);
  rect(5, 5, 393, 305);
  fill(0, 0, 0);     
  rect(402, 5, 393, 305);
  
  GPointsArray points1 = new GPointsArray(beerArray1.length);
    for (int i = 0; i < beerArray1.length; i++) {
      points1.add(i, beerArray1[i]);
   }
   
  GPointsArray points2 = new GPointsArray(beerArray2.length);
    for (int i = 0; i < beerArray2.length; i++) {
      points2.add(i, beerArray2[i]);
   }  
   
  GPointsArray points3 = new GPointsArray(beerArray3.length);
    for (int i = 0; i < beerArray3.length; i++) {
      points3.add(i, beerArray3[i]);
   }  
   
   
  plot1.setPoints(points1);
  plot1.beginDraw(); 
  plot1.drawBox();
  plot1.drawXAxis();
  plot1.drawYAxis();
  plot1.drawTitle();
  plot1.drawPoints();
  plot1.drawGridLines(GPlot.BOTH);
  plot1.drawLines(); 
  //plot1.drawHorizontalLine(pidtarget, color(255, 0, 255), 1);
  plot1.drawLabels();
  plot1.endDraw();
  
  plot2.setPoints(points2);  
  plot2.beginDraw(); 
  //plot2.drawBox();
  //plot2.drawXAxis();
  //plot2.drawYAxis();
  //plot2.drawTitle();
  plot2.drawPoints();
  //plot2.drawGridLines(GPlot.BOTH);
  plot2.drawLines(); 
  //plot2.drawLabels();
  plot2.endDraw();
  
  plot3.setPoints(points3);  
  plot3.beginDraw(); 
  //plot2.drawBox();
  //plot2.drawXAxis();
  //plot2.drawYAxis();
  //plot2.drawTitle();
  plot3.drawPoints();
  //plot2.drawGridLines(GPlot.BOTH);
  plot3.drawLines(); 
  //plot2.drawLabels();
  plot3.endDraw(); 
  
  
}