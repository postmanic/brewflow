
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
#include <avr/wdt.h>

// Hardware setup
// Uses Dallas library for one wire bus.
// Uses 4 x DS1820B 2 for each tank. 1 top (mash) and 1 bottom (circulating).
// Uses DFROBOT L298P 2A motor shield.
// Uses 2 x SSR 40A for PID controlled PWM output to heaters MLT and HLT.
// Beersmith 

#define One_Wire_Bus (3)  // Thermometers.
#define pumpcontrol (4)  // Pump control.
#define pumppwm     (5)  // Pump PWM.
#define heatcontrol (9)  // MLT heater PWM.

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

static double  xk_1;
static double  xk_2;

double kc = 1.2, ti = 2.5, td = 0.5, ts = 20;
double k0, k1, k2, k3, pp, pi, pd;
double ek, ek_1, ek_2, yk_1, yk_2;

// Controller settings

// Steeptime - When does timer start
// Temp sensing - Which sensor is used. Combination
// Pump setting - Pump ventilation. Pumpduring steps

byte pumpspeed; // ( 0 - 100% )

int steptimer, mashintimer, step1timer, step2timer, step3timer, step4timer, mashouttimer = 1, boiltimer;          // (0 - 100 minutter)
byte steptarget, mashintarget, step1target,step2target, step3target, step4target, mashouttarget, boiltarget;  // (0 - 110 grader)
double heatspeed, temp[3];      // (Kan muligvis converteres til unsigned integer hvis der er behov)

int temp_sens;
byte debugtemp1, debugtemp2; // (0 - 255 degrees)
byte step_x;

boolean stringComplete = false;
boolean ilock          = false;   // Water added switch.
boolean mlock          = false;   // Grain added switch.
boolean vrg            = false;   // PID switch.
boolean pumpstate     = false;   // Pump switch.

int ticks, pumpvent, pumptimer, wspeed1;
String inputString = "", bbuf = "", cbuf = "";

int lastupdatestatus;    // Holds time for when status was sent to webclient.
int lastupdatesettings;  // Holds time for when settings was sent to webclient.
int lastupdateui;        // Holds time for when UI received the last update.
int lastupdatepid;       // Holds time for when PID received the last update.

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);
DeviceAddress T1 = { 0x28, 0x75, 0xE8, 0x26, 0x06, 0x00, 0x00, 0x21 };
DeviceAddress T2 = { 0x28, 0xFF, 0x69, 0x15, 0x06, 0x00, 0x00, 0xC2 };


void loop(void) {
   
  update_temperatures(); // altid da 
  update_pid();          // kun hvis VRG er aktiv
  update_pump();         // kun hvis der er et status skifte
  // update_timer;
  // update_graph;
  send_status(1);
  get_input();
  
  switch (step_x) {

    case 1: // MashIn
      if (vrg == false){ 
        vrg = true;
      }
      
      if ((millis()/1000 < (pumptimer + 5)) || (millis()/1000 > (pumptimer + 10) && millis()/1000 < (pumptimer + 15)) ){
        if (pumpstate == 0){
          pumpstate = true;
          wspeed1 = 60;
        }  
      }
      else {
        if (pumpstate == 1){
          pumpstate = false;
          wspeed1 = 0;
          pumpvent++;
        }
      }
      
      if (temp[0] >= mashintarget && step_x == 1 && ilock == true && pumpvent == 2){
        step_x = 2;
      }
    break; 

    //
    // Der er ventileret og Mash In temperatur er nået, nu skal der tilsættes malt og omrøres.
    // Når der er tilsat malt og omrørt skal bruger acceptere.
    // Derefter videre til næste step.
    //

    case 2: // MashIn grain added.
      if (ilock == true && mlock == true){
        steptimer = (millis()/1000) + (60 * step1timer);   // step 1        
        steptarget = step1target;       
        step_x = 3;
        init_pid();
        //vrg = 1;
        pumpstate = true;
        wspeed1 = 60;
      }   
    break; 

    case 3: // Step 1.

      if (millis()/1000 < (steptimer)){
      // Timer running
      }
      else {
      // step 1 done
      step_x = 4;     
      steptimer = millis()/1000 + (60 * step2timer);
      steptarget = step2target;
      vrg = true;
      delay(50);
      }
      
    break;

     case 4: // Step 2.
      if (millis()/1000 < (steptimer)){
      // Timer running
      }
      else {
      // Step 2 done
      step_x = 5;      
      steptimer = millis()/1000 + (60 * step3timer);
      steptarget = step3target;         
      vrg = true;
      delay(50);  
      }
      
    break;
    
     case 5: // Step 3.
      if (millis()/1000 < (steptimer)){
      // Timer running
      }
      else {
      // Step 3 done
      step_x = 6;      
      steptimer = millis()/1000 + (60 * step4timer);
      steptarget = step4target;
      vrg = true;
      delay(50);
      
      }
    break; 
    
      case 6: // Step 4.
      if (millis()/1000 < (steptimer)){
      // Timer running
      }
      else {
      // Step 4 done
      step_x = 7;     
      steptimer = millis()/1000 + (60 * mashouttimer);
      steptarget = mashouttarget;      
      vrg = true;
      delay(50);
      }
    break; 

      case 7: // Mash Out.
      if (millis()/1000 < (steptimer)){
      // Timer running
      }
      else {
      // MashOut done, next Boil
      step_x = 8;      
      steptimer = millis()/1000 + (60 * boiltimer);
      steptarget = boiltarget;     
      vrg = true;
      delay(50);
       }
    break;

      case 8: // Boil.
      if (millis()/1000 < (steptimer)){
        pumpstate = false;
        wspeed1 = 60;
      }
      else {
      // Boil done, finished.
      vrg = false;
      step_x = 9;
      delay(50);
      }
    break; 

      case 9: // Done.

      vrg = false;
      pumpstate = false;
      wspeed1 = 0;
      
    break; 

 
    //
    // System er idle og afventer bruger har påfyldt vand (ilock) og opskrift er loadet (receipe).
    //
 
    default:
    if (ilock == true && mashintarget != 0 && step1target != 0 && step1timer !=0 ) { 
      step_x = 1;
      steptarget = mashintarget;
      steptimer = mashintimer; 
      pumptimer =  millis()/1000;
    }
    break;
  }
}
