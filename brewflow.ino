
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

#include <OneWire.h>
#include <DallasTemperature.h>
#include <avr/wdt.h> // used for resetting system if things go tits up.

// Hardware setup
// Uses Dallas library for one wire bus.
// Uses 4 x DS1820B 2 for each tank. 1 top (mash) and 1 bottom (circulating)
// Uses DFROBOT L298P 2A motor shield
// Uses 2 x SSR 40A for PID controlled PWM output to heaters MLT and HLT

#define One_Wire_Bus (3)  // Thermometers.
#define pump_control (4)  // Pump control.
#define pump_pwm     (5)  // Pump PWM.
#define heat_control (9)  // MLT heater PWM.

//#define SECS_PER_MIN  (60UL)
//#define SECS_PER_HOUR (3600UL)
//#define SECS_PER_DAY  (SECS_PER_HOUR * 24L)
//#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)
//#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN)
//#define numberOfHours(_time_) (( _time_% SECS_PER_DAY) / SECS_PER_HOUR)
//#define elapsedDays(_time_) ( _time_ / SECS_PER_DAY)
#define TWENTY_SECONDS (400)
//#define TEN_SECONDS (200)
//#define FIVE_SECONDS (100)
//#define ONE_SECOND (20)
#define T_50MSEC (50)

// Controller settings

// Steeptime - When does timer start
// Temp sensing - Which sensor is used. Combination
// Pump setting - Pump ventilation. Pumpduring steps

byte pump_speed, intensity;

byte target[8];

//
// receipe[18]
//
// [0] MashIn temperature
// [1] Step1 temperature
// [2] Step2 temperature
// [3] Step3 temperature
// [4] Step4 temperature
// [5] MashOut temperature
// [6] Boil temperature
// [7] MashIn timer
// [8] Step1 timer
// [9] Step2Rise timer
// [10] Step2 timer
// [11] Step3Rise timer
// [12] Step3 timer
// [13] Step4Rise timer
// [14] Step4 timer
// [15] MashOutRise timer
// [16] MashOut timer
// [17] Boil timer
//

int receipe[18];
int steptimer[6];

int temp_sens;
float temp[5];
byte debugtemp1, debugtemp2;

boolean stringComplete = false;
boolean ilock = false;           // Interlock. Can be released by user acknowledging water has been filled into tank.
boolean mlock = false;           // Interlock. Can be released by user acknowledging malt has been added to tank.
boolean vrg   = false;           // Switch for turning PID on and off.
boolean pump1state = 0;          // If true pump 1 is running.

int ticks, step_x, pumpvent, pumptimer, wspeed1;
String inputString = "", bbuf = "", cbuf = "";
int lastupdatestatus; // Holds time for when status was sent to webclient.
int lastupdatesettings; // Holds time for when status was sent to webclient.
int lastupdateui; // Holds time for when UI received the last update.
int lastupdatepid; // Holds time for when UI received the last update.
// Control setup

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

DeviceAddress T1 = { 0x28, 0x75, 0xE8, 0x26, 0x06, 0x00, 0x00, 0x21 };
DeviceAddress T2 = { 0x28, 0xFF, 0x69, 0x15, 0x06, 0x00, 0x00, 0xC2 };

void loop(void) {
   
  update_pid();
  update_pump();
  //update_ui(10);
  send_status(1);
  //send_settings();
  user_input();
  update_temperatures();
  switch (step_x) {

    //
    // Mash In and ventilation of pump 1.
    // 

    case 1:

      //
      // Mash In
      // Mash In starter når bryggeren har tilføjet vand. ilock skal være sand.
      // PID startes og varmer vandet til emperaturen for Mash In er nået.
      // og er afsluttet når temperaturen er nået.
      // 
      // Inden PID styring tændes dobbeltcheckes at bruger har accepteret at der er påfyldt vand.
      //
      // Case 1 kan kun initieres fra ilock og kun når der ikke er tilsat malt
      // Når ilock sættes til sand af brygger startes PID den temperatur der skal rammes er sat af brygger 

      //  if (bbuf_int == 1 && ilock == false && target[1] > 40 && step_x == 0){
      //    step_x = 1;
      //    target[0] = target[1];
      //    pumptimer =  millis()/1000;
      //     delay(2);
      //    ilock = true;
      
      //
      if (ilock == true && mlock == false) {

      //
      // PID tændes
      //
      
      vrg = 1;

      //
      // Ventilering af pumpe efter der er påfyldt vand. Der ventileres 5 sekunder, pause 5 sekunder, ventilering 5 sekunder.
      // Hvornår skal der ventileres. Bedste bud er når der er påfyldt vand men det bedtyder at man også skal huske at flytte slanger.
      // Jeg afprøver når jeg har modtaget slanger.
      //
      
      if ((millis()/1000 < (pumptimer + 5)) || (millis()/1000 > (pumptimer + 10) && millis()/1000 < (pumptimer + 15)) ){
        // hvis ikke pumpen er tændt skal den tændes
        if (pump1state == 0){
          pump1state = 1;
          wspeed1 = 60;
        }  
      }
      else {
        
        //
        // Pumpe slukkes
        //
        
        if (pump1state == 1){
          pump1state = 0;
          wspeed1=0;
          pumpvent++;
        }
      }

      //
      // Når temperturen er nået og der er ventileret skal vi videre til næste trin.
      //
      
      if (temp[0] >= target[0] && step_x == 1 && ilock == true && pumpvent == 2){
        step_x = 2;
      }} 
    break; 

    //
    // Der er ventileret og Mash In temperatur er nået, nu skal der tilsættes malt og omrøres.
    // Når der er tilsat malt og omrørt skal bruger acceptere.
    // Derefter videre til næste step.
    //
    
    case 2:
      if (ilock == true && mlock == true){
        steptimer[0] = (millis()/1000) + (60 * steptimer[1]);           
        target[0] = target[2];       
        step_x = 3;
        vrg = 1;
        pump1state = 1;
        wspeed1 = 60;
      }   
    break; 


    case 3: // Step 1.
      if (millis()/1000 < (steptimer[0]) && step_x == 3){
      // Timer and PID running
      }
      else {
        
      // Step done
      //
      // Hvis target[3] = 40 og steptimer [2] = 0 then case 9 
      //
      // Der skal kunne vælges om risetime skal være med i Mash In, Step 1, en kombination eller slet ikke. 
      // Pumpe
      //
      //
      
      if (steptimer[2] == 0) {
        steptimer[0] = millis()/1000 + (60 * 15);
        target[0] = target[6];
        step_x = 7;
        break;        
      }

      steptimer[0] = millis()/1000 + (60 * steptimer[2]);
      target[0] = target[3];
      step_x = 4;
      vrg = 1;
      }
      
    break;

     
     case 4: // Step 2.
      if (millis()/1000 < (steptimer[0]) && step_x == 4){
      // Timer and PID running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[3]);
      step_x = 5;
      vrg = 1;
      target[0] = target[4];      
      }
      
    break;
    
     case 5: // Step 3.
      if (millis()/1000 < (steptimer[0]) && step_x == 5){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[4]);
      step_x = 6;
      vrg = 1;
      target[0] = target[5];
      }
    break; 
    
      case 6: // Step 4.
      if (millis() < (steptimer[0] * 1000) && step_x == 6){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[5]);
      step_x = 7;
      vrg = 1;
      target[0] = target[6];
      }
    break; 

      case 7: // Mash Out.
      if (millis() < (steptimer[0] * 1000) && step_x == 7){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[6]);
      step_x = 8;
      vrg = 1;
      target[0] = target[7];
      }
    break;

      case 8: // Boil.
      if (millis() < (steptimer[0] * 1000) && step_x == 8){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[5]);
      step_x = 9;
      vrg = 0;
      }
    break; 
 
    default:
      // statements, allways statements
    break;
  }
 
}
