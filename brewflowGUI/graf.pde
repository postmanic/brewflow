 
import grafica.*;
 
public void createGRAF(){
  
   
  plot1 = new GPlot(this);
  plot1.setPos(0, 300);
  plot1.setMar(60, 70, 40, 70);
  plot1.setDim(700, 400);
  plot1.setAxesOffset(4);
  plot1.setTicksLength(5);
  plot1.setPointColor(color(50, 50, 255));
  plot1.setPointSize(2);
  plot1.setLineColor(color(50, 50, 255));
  plot1.setYLim(0,110);
  plot1.setTitleText("Temperature");
  plot1.getYAxis().setAxisLabelText("T (Celsius)");
  plot1.getXAxis().setAxisLabelText("Ticks (20 seconds)");
  plot1.getXAxis().setNTicks(5);
  plot1.activatePointLabels();
  
  plot2 = new GPlot(this);
  plot2.setPos(0, 300);
  plot2.setMar(60, 70, 40, 70);
  plot2.setDim(700, 400);
  plot2.setYLim(0,110); 
  plot2.setPointColor(color(55, 255, 55));
  plot2.setPointSize(2);
  plot2.setLineColor(color(55, 255, 55));
  //plot1.activatePanning();
  //plot1.activateZooming(1.2, CENTER, CENTER);
  //plot1.activatePointLabels();
  //plot1.activateCentering(LEFT, GPlot.CTRLMOD);  
  
  plot3 = new GPlot(this);
  plot3.setPos(0, 300);
  plot3.setMar(60, 70, 40, 70);
  plot3.setDim(700, 400);
  plot3.setYLim(0,110);
  plot3.setPointColor(color(255, 55, 55));
  plot3.setPointSize(2);
  plot3.setLineColor(color(255, 55, 55));
  //plot1.activatePanning();
  //plot1.activateZooming(1.2, CENTER, CENTER);
  //plot1.activatePointLabels();
  //plot1.activateCentering(LEFT, GPlot.CTRLMOD);     
   

}