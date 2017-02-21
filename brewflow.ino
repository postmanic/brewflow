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
#define pump1ctrl (4)     // Pump 1 control.
#define pump1pwm  (5)     // Pump 1 PWM.
//#define pump2ctrl (6)     // Pump 2 control.
//#define pump2pwm  (7)     // Pump 2 PWM.
#define heat1 (9)         // MLT heater PWM.
//#define heat2 (10)        // HLT heater PWM.

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

double kc = 1.2, ti = 2.5, td = 0.5, ts = 5;
double k_lpf, k0, k1, k2, k3, lpf1, lpf2, pp, pi, pd;
double ek, ek_1, ek_2, xk_1, xk_2, yk_1, yk_2;

byte pump1speed, intensity, debugtemp1, debugtemp2;
byte target[8];
int steptimer[6];
byte temp[5];

boolean stringComplete = false;
boolean ilock = false; // Interlock. Can be released by user acknowledging water has been filled into tank.
boolean mlock = false; // Interlock. Can be released by user acknowledging malt has been added to tank.
boolean vrg = false; // Switch for turning PID on and off.
boolean pump1state = false; // If true pump 1 is running.

int ticks, step_x, pumpvent, pumptimer;
String inputString = "", bbuf = "", cbuf = "";
int lastupdatestatus; // Holds time for when status was sent to webclient.
int lastupdatesettings; // Holds time for when status was sent to webclient.
int lastupdateui; // Holds time for when UI received the last update.
int lastupdatepid; // Holds time for when UI received the last update.
// Control setup

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

void loop(void) {

  read_temperatures();
  update_pid();
  //update_ui(10);
  send_status(1); 
  //send_settings(20);
  user_input();

  switch (step_x) {

    //
    // Mash In and ventilation of pump 1.
    // 

    case 1:

      //
      // PID slåes til, hvorefter temperaturen styres automatisk.
      // Hvis der checkes skal der også være en handling hvis ikke alt er normalt. WDT reset.
      // Inden PID styring tændes dobbeltcheckes at bruger har accepteret at der er påfyldt vand.
      //
      
      if (ilock == true && mlock == false) {
      vrg = 1; 
            
      //  
      // Ventilering af pumpe efter der er påfyldt vand. Der ventileres 5 sekunder, pause 5 sekunder, ventilering 5 sekunder.
      // Hvornår skal der ventileres. Bedste bud er når der er påfyldt vand men det bedtyder at man også skal huske at flytte slanger.
      // Jeg afprøver når jeg har modtaget slanger.
      // 
      
      if ((millis()/1000 < (pumptimer + 5)) || (millis()/1000 > (pumptimer + 10) && millis()/1000 < (pumptimer + 15)) ){
        // hvis ikke pumpen er tændt skal den tændes
        if (pump1state == false){
          pump_set1(100);
        }  
      }
      else {
        
        //
        // Pumpe slukkes
        //
        
        if (pump1state == true){
          pump_set1(0);
          pumpvent++;
        }
      }

      //
      // Når temperturen er nået og der er ventileret skal vi videre til næste trin.
      //
      
      if (temp[1] >= target[1] && step_x == 1 && ilock == true && pumpvent == 2){
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
        step_x = 3;
        vrg = 0;
      }   
    break; 


    case 3: // Step 1.
      vrg = 1;
      target[0] = target[2];
      if (millis()/1000 < (steptimer[0]) && step_x == 3){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[2]);
      step_x = 4;
      vrg = 0;
      }
      
    break;

     
     case 4: // Step 2.
      vrg = 1;
      target[0] = target[3];
      if (millis()/1000 < (steptimer[0]) && step_x == 4){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[3]);
      step_x = 5;
      vrg = 0;
      }
      
    break;
    
     case 5: // Step 3.
      vrg = 1;
      target[0] = target[4];
      if (millis()/1000 < (steptimer[0]) && step_x == 5){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[4]);
      step_x = 6;
      vrg = 0;
      }
    break; 
    
      case 6: // Step 4.
      vrg = 1;
      target[0] = target[5];
      if (millis() < (steptimer[0] * 1000) && step_x == 6){
      // Timer running
      }
      else {
      // Step done
      steptimer[0] = millis()/1000 + (60 * steptimer[5]);
      step_x = 7;
      vrg = 0;
      }
    break; 
 
    default:
      // statements, allways statements
    break;
  }
 
}
