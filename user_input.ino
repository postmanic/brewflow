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

 
  
void get_input(){

  if (stringComplete){

    cbuf = inputString.substring(0,4);

    bbuf = inputString.substring(4);

    long bbuf_int = bbuf.toInt(); // needs checking for correct input and reason for converting to integer is unknown

    long cbuf_int = cbuf.toInt(); // needs checking for correct input and reason for converting to integer is unknown


    switch (cbuf_int) {
      
      //case 1111: // System will reset AVR if no response is received from brewflowGUI.
        //wdt_reset();
      //break;
      
      //
      // user input for setting step parametres. Ikke særligt fikst, men det virker
      //
      
      case 9010:  // Set step temp to bbuf. 9010xx where xx is temperature in celcius degrees. Mash In
        mashintarget = bbuf_int;
        break;
      case 9011:  // Set step temp to bbuf. 9011xx where xx is temperature in celcius degrees. Step 1
        step1target = bbuf_int;
        break;
      case 9012:  // Set step temp to bbuf. 9012xx where xx is temperature in celcius degrees. Step 2
        step2target = bbuf_int;
        break;
      case 9013:  // Set step temp to bbuf. 9013xx where xx is temperature in celcius degrees. Step 3
        step3target = bbuf_int;
        break;
      case 9014:  // Set step temp to bbuf. 9014xx where xx is temperature in celcius degrees. Step 4
        step4target = bbuf_int;
         break;
      case 9015:  // Set step temp to bbuf. 9015xx where xx is temperature in celcius degrees. Mash Out
        mashouttarget = bbuf_int;
         break;
      case 9016:  // Set step temp to bbuf. 9015xx where xx is temperature in celcius degrees. Boil
        boiltarget = bbuf_int;
        break;          
      case 9021:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 1
        step1timer = bbuf_int;
        break;
      case 9022:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 2
        step2timer = bbuf_int;
        break;
      case 9023:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 3
        step3timer = bbuf_int;
        break;
      case 9024:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Step 4
        step4timer = bbuf_int;
        break;      
      case 9025:  // Set step timer to bbuf. 9015xx where xx is time in minutes. Boil
        boiltimer = bbuf_int;
        break;   

      //
      // Set temperature sensor output. Debug option.
      //

      case 2010:  // Indstilling af debug temp. Simulerer temp probe1
        debugtemp1 = bbuf_int;
        debugtemp1 = debugtemp1 / 10;
        break;        
      case 2020:  // Indstilling af debug temp. Simulerer temp probe1
        debugtemp2 = bbuf_int;
        debugtemp2 = debugtemp2 / 10;        
        break;  

      //
      // interlocks that needs to be input by user.
      //

      case 9041:  // Bruger bekræfter at der er påfyldt vand. ilock kan kun sættes fra initialisering.
        if (bbuf_int == 1 && ilock == false && step_x == 0){
          ilock = true;
        }
        break;
      case 9042:  // User acknowledges that there is water in tank. No water will damage equipment
        if (bbuf_int == 2 && step_x == 2 && ilock == true){
          mlock = true;
        }
        break;

      //
      // Manuel control of system
      //
      
      case 9090: // Hvis der tilsat vand og Mash In temp er indtastet bliver menu sat til 1 
        wspeed1 = bbuf_int;
        update_pump();        
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
