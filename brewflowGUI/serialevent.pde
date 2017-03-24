

void serialEvent(Serial myPort) {
  try {
    String myString = myPort.readStringUntil(lf);
    print(myString);
    String myArray[] = split(myString, ',');
    int command = int(myArray[0]);
    switch(command) {
      
      case 1012:  
        a++; 
        temp_0   = int (myArray[3])/10; 
        temp_1   = int (myArray[4])/10; 
        temp_2   = int (myArray[5]);
        updatestatus   = int (myArray[6]);   
        beerArray1 = append(beerArray1, temp_0);
        beerArray2 = append(beerArray2, temp_1);
        beerArray3 = append(beerArray3, temp_2);
      break;
      
      case 1010:
        // add reading to graf arrayList 
        temp_0       = int (myArray[2]); 
        temp_1   = int (myArray[3]); 
        temp_2   = int (myArray[3]); 
        int ilock     = int (myArray[4]);
        int mlock     = int (myArray[5]);
        int vrg       = int (myArray[6]);
        int intensity = int (myArray[7]);
        int pump1state = int (myArray[8]);
        float pump1speed = int (myArray[9]);
        int step_x = int (myArray[10]);    
        updatestatus = int (myArray[13]);
        pidtarget = int (myArray[11]);
        int pidtimer = int (myArray[12]);
       // label14.setText("Case "+int(step_x)+" " + updatestatus);
        
        if (vrg > 0) {
          label5.setLocalColorScheme(GCScheme.RED_SCHEME);
          label5.setText(int(intensity)+"%");
        }
        else {
          label5.setLocalColorScheme(GCScheme.BLUE_SCHEME);
          label5.setText("  OFF");
        }

        if (pump1state == 1) {
          label12.setLocalColorScheme(GCScheme.RED_SCHEME);
          label12.setText(str(pump1speed)+"%");
        }
        else {
          label12.setLocalColorScheme(GCScheme.BLUE_SCHEME);
          label12.setText("  OFF");
        }
    
        if (ilock == 1) {
          label21.setLocalColorScheme(GCScheme.GREEN_SCHEME);
          label21.setText("OK");
        }
        else {
          label21.setLocalColorScheme(GCScheme.RED_SCHEME);
          label21.setText("NO");
        }
    
    if (mlock == 1) {
      label11.setLocalColorScheme(GCScheme.GREEN_SCHEME);
      label11.setText("OK");
    } else {
      label11.setLocalColorScheme(GCScheme.RED_SCHEME);
      label11.setText("NO");
    }
    
    if (temp_1/10 >= 0) {
      label18.setLocalColorScheme(GCScheme.GREEN_SCHEME);
    } else {
      label18.setLocalColorScheme(GCScheme.RED_SCHEME);
    }

    if (temp_2/10 >= 0) {
      label17.setLocalColorScheme(GCScheme.GREEN_SCHEME);
    } else {
      label17.setLocalColorScheme(GCScheme.RED_SCHEME);
    }



    if  (step_x == 3) {   
      statustext = "PID is 'ON'. Target is 'Step 1' temperature @ " + pidtarget + "°C" + "Timer is running, time left " + (pidtimer - updatestatus)/60;
    }

    if  (step_x == 2) {   
      statustext = "'MashIn' temperature @ " + pidtarget + "°C is reached. Ready for MashIn. Add malt and continue.";
    }

    if  (step_x == 1) {   
      statustext = "PID is 'ON'. Target is 'MashIn' temperature @ " + pidtarget + "°C";
    
    }
   
    
    if (step_x == 0) { 
       
      statustext = "System is idle. PID is 'OFF'. Pump is 'OFF'. ";      
    
      if (ilock == 0) {
      statustext += "Waiting for water. ";
      }
      
      if (receipe == 0) {
      statustext += "Waiting for Receipe. ";
      }

    }
    
    
    label20.setText(statustext);     
    label1.setText(pidtarget+"°");      
    label3.setText(str(temp_0/10)+"°"); 
    label6.setText(str(temp_1/10)+"°");

    break;
  }
  




} 
  catch (RuntimeException e) {
          myPort.clear();
  }
}  