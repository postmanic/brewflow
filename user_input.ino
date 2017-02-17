/*
 * This file is part of brewflow.
 *
 * brewflow is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * brewflow is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with brewflow.  If not, see <http://www.gnu.org/licenses/>.
 */
 
void user_input(){
  if (stringComplete){
    cbuf = inputString.substring(0,4);
    bbuf = inputString.substring(4);
    long bbuf_int = bbuf.toInt(); // needs checking for correct input and reason for converting to integer is unknown
    long cbuf_int = cbuf.toInt(); // needs checking for correct input and reason for converting to integer is unknown
    switch (cbuf_int) {
      
      case 1111: // System will reset AVR if no response is received from brewflowGUI.
        wdt_reset();
      break;  

      case 9000:  // verbose 90001 is on and 90000 is off
        commands = bbuf_int;
      break;
      
      //
      // user input for setting step temperatures.
      //
      
      case 9010:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Mash In
        target1 = bbuf_int;
      break;
      case 9011:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Step 1
        target2 = bbuf_int;
      break;
      case 9012:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Step 2
        target3 = bbuf_int;
      break;
      case 9013:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Step 3
        target4 = bbuf_int;
      break;
      case 9014:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Step 4
        target5 = bbuf_int;
      break;
      case 9015:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Mash Out
        target6 = bbuf_int;
      break;

      //
      // User input for setting step timers
      //
      
      case 9021:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 1
        steptimer1 = bbuf_int;
      break;
      case 9022:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 2
        steptimer2 = bbuf_int;
      break;
      case 9023:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 3
        steptimer3 = bbuf_int;
      break;
      case 9024:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 4
        steptimer4 = bbuf_int;
      break;      
      case 9030:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Boil
        steptimer5 = bbuf_int;
      break;   

      //
      // Set temperature sensor output. Debug option.
      //

      case 2010:  // Indstilling af debug temp. Simulerer temp probe1
        debugtemp1 = bbuf_int;
      break;        
      case 2020:  // Indstilling af debug temp. Simulerer temp probe1
        debugtemp2 = bbuf_int;
      break;  

      //
      // interlocks that needs to be input by user.
      //

      case 9041:  // User acknowledges that there is water in tank. No water will damage equipment
        if (bbuf_int == 1){
          ilock = true;
        }
      break;
      case 9042:  // User acknowledges that there is water in tank. No water will damage equipment
        if (bbuf_int == 2 && step_x == 2 && ilock == true){
          mlock = true;
        }
      break;

      //
      // Start brewing.
      //

      case 9050: // Hvis der tilsat vand og Mash In temp er indtastet bliver menu sat til 1 
        if (ilock == true &&  target1 > 0) {
          step_x = 1;
          pumptimer =  millis();
          delay(2);
        }
      break; 

      //
      // Manuel control of system
      //
      
      case 9072: // Set pump1 to 'ON' and PWM to bbuf. 9020xxx where xxx is motor turn in percentage
        pump_set1(bbuf_int);
      break;
      case 9073: // Set pump1 to 'OFF'.
        pump_set1(0);
      break;
      case 9074: // Set MLT PID to 'ON' and set temp to bbuf. 9030xxx where xxx is temperature in celcius degrees. Manuel control  
        vrg = 1;
        target1 = bbuf_int;
      break;
      case 9075: // Set MLT PID to off. 
        vrg = 0;
      break; 

      //
      // Reset system
      //

      case 9999: // Turn of system by resetting AVR.
        wdt_enable(WDTO_15MS);
        while(1){};
      break;
    
      default:
        // statements, allways statements
      break;
    }
    inputString = "";
    stringComplete = false;
  }
}
