 
import grafica.*;
 
public void createGRAF(){

// Create the first plot

  plot1 = new GPlot(this);
  plot1.setPos(0, 300);
  plot1.setMar(60, 70, 40, 70);
  plot1.setDim(700, 400);
  plot1.setAxesOffset(4);
  plot1.setTicksLength(2);
  plot1.setPointColor(90);
  plot1.setPointSize(1);
  plot1.setLineColor(0);
  plot1.setYLim(0,110);
  //plot1.setXLim(0,beerArray.length);
  //plot1.drawHorizontalLine(73, 190, 0);
  // Prepare the points
  GPointsArray points = new GPointsArray(beerArray.length);
    for (int i = 0; i < beerArray.length; i++) {
      points.add(i, beerArray[i]);
    }
  plot1.setPoints(points);
  
  plot1.setTitleText("Temperature");
  plot1.getYAxis().setAxisLabelText("T (Celsius)");
  plot1.getXAxis().setAxisLabelText("Time (minutes)");
 



}