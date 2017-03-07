 
import grafica.*;
 
//
// Transforms from degree Celsius to degree Kelvin
//
float[] celsiusToKelvin(float[] celsius){
  float[] kelvin = new float[celsius.length];
 
  for(int i = 0; i < celsius.length; i++){
    kelvin[i] = 273.15 + celsius[i];
  }
 
  return kelvin;
}

public void createGRAF(){

// Create the first plot
  plot1 = new GPlot(this);
  plot1.setPos(0, 300);
  plot1.setMar(60, 70, 40, 70);
  plot1.setDim(700, 400);
  plot1.setAxesOffset(4);
  plot1.setTicksLength(0);
 
   // Prepare the points
  int nPoints = 500;
  GPointsArray points = new GPointsArray(nPoints);
 
  for (int i = 0; i < nPoints; i++) {
    points.add(i, 30 + 10*noise(i*0.1));
  }  
     
  // Set the points, the title and the axis labels
  plot1.setPoints(points);
  plot1.setTitleText("Temperature");
  plot1.getYAxis().setAxisLabelText("T (Celsius)");
  plot1.getXAxis().setAxisLabelText("Time (minutes)");
 
  // Activate the panning (only for the first plot)
  plot1.activatePanning();
}