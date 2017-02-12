/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 *
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
          
      case 9010:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees
        target = bbuf_int;
      break;

      case 9015:  // Set step timer to bbuf. 9015xx where xx is time in mnutes
        steptimer = bbuf_int;
      break;
      
      case 9019:  // User acknowledges that there is water in tank. No water will damage equipment
        ilock = bbuf_int;
      break;
    
      case 9020: // Set pump1 to 'ON' and PWM to bbuf. 9020xxx where xxx is motor turn in percentage
        pump_set1(bbuf_int);
      break;

      case 9025: // Set pump1 to 'OFF'.
        pump_set1(0);
      break;
      
      case 9030: // Set MLT PID to 'ON' and set temp to bbuf. 9030xxx where xxx is temperature in celcius degrees. Manuel control  
        vrg = 1;
        target = bbuf_int;
      break;

      case 9035: // Set MLT PID to off. 
        vrg = 0;
      break; 

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
