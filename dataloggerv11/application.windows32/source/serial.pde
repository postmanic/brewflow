   import processing.serial.*;
   import g4p_controls.*;
   import controlP5.*;   
 
 
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

void SerialPortSetup(){
   
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

void serialEvent(Serial myPort) {


  /* ============================================================    
      Read the next byte that's waiting in the buffer. 
     ============================================================   */
 
    String myString = myPort.readStringUntil(lf);
    print(myString);
    String myArray[] = split(myString, ',');
    int command = int(myArray[0]);

switch(command) {

  
/*  ==================================================================
      Recieve temperature and time from chip, update graph      
    ==================================================================  */
    
    case 1010: // Status
     
     float mlttemp = int(myArray[1]);
     float hlttemp = int(myArray[2]);         
     float targettemp = int(myArray[2]); 
     float myticks = int(myArray[2]);    
     
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
