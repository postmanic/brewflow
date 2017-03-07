 
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

public void createGRAF(int x, int y){

// Create the first plot
  plot1 = new GPlot(this);
  plot1.setPos(0, 300);
  plot1.setMar(60, 70, 40, 70);
  plot1.setDim(700, 400);
  plot1.setAxesOffset(4);
  plot1.setTicksLength(4);
 
  // Create the second plot with the same dimensions
  plot2 = new GPlot(this);
  plot2.setPos(plot1.getPos());
  plot2.setMar(plot1.getMar());
  plot2.setDim(plot1.getDim());
  plot2.setAxesOffset(4);
  plot2.setTicksLength(4);
   // Prepare the points
  int nPoints = x;
  GPointsArray points = new GPointsArray(x);
 

    points.add(x, y);
  
  // Set the points, the title and the axis labels
  plot1.setPoints(points);
  plot1.setTitleText("Temperature");
  plot1.getYAxis().setAxisLabelText("T (Celsius)");
  plot1.getXAxis().setAxisLabelText("Time (minutes)");
 
  plot2.getRightAxis().setAxisLabelText("T (Kelvin)");
 
  // Make the right axis of the second plot visible
  plot2.getRightAxis().setDrawTickLabels(true);
 
  // Activate the panning (only for the first plot)
  plot1.activatePanning();
}