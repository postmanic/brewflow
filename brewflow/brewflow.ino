/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 * PID Copyright 2001 - 2015 Emile van de Logt
 * <http://www.vandelogt.nl>
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

#include <OneWire.h>
#include <DallasTemperature.h>
#include <avr/io.h>
#include <avr/wdt.h>

// Hardware setup

#define One_Wire_Bus (3)  // Thermometers.

int pump[] = {5,6,11};
boolean pumpstate[] = {LOW,LOW,LOW};
int pumpspeed[] = {0,0,0};

#define heat_1 (9)        // MLT heater [mlth].
#define heat_2 (10)       // HLT heater [hlth].

#define pump_1_ctrl (4)   // Pump 1 control output.
#define pump_2_ctrl (7)   // Pump 2 control output.
#define pump_3_ctrl (8)   // Pump 3 control output.

double heat_1_speed;
double heat_2_speed;

// Time setup

#define SECS_PER_MIN  (60UL)
#define SECS_PER_HOUR (3600UL)
#define SECS_PER_DAY  (SECS_PER_HOUR * 24L)
#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)
#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN)
#define numberOfHours(_time_) (( _time_% SECS_PER_DAY) / SECS_PER_HOUR)
#define elapsedDays(_time_) ( _time_ / SECS_PER_DAY)
#define TWENTY_SECONDS (400)
#define TEN_SECONDS (200)
#define FIVE_SECONDS (100)
#define ONE_SECOND (20)
#define T_50MSEC (50)
#define GMA_HLIM (100.0)
#define GMA_LLIM (0.0)

// PID setup

double v1kc = 1.2, v1ti = 2.5, v1td = 0.5, v1ts = 5;
double v1k_lpf, v1k0, v1k1, v1k2, v1k3, v1lpf1, v1lpf2, v1pp, v1pi, v1pd;
double v2kc = 1.2, v2ti = 2.5, v2td = 0.5, v2ts = 5;
double v2k_lpf, v2k0, v2k1, v2k2, v2k3, v2lpf1, v2lpf2, v2pp, v2pi, v2pd;
static double v1ek_1, v1ek_2, v1xk_1, v1xk_2, v1yk_1, v1yk_2, v1lpf_1, v1lpf_2;
static double v2ek_1, v2ek_2, v2xk_1, v2xk_2, v2yk_1, v2yk_2, v2lpf_1, v2lpf_2;
boolean vrg1 = false;
boolean vrg2 = false;
int v1ts_ticks, v2ts_ticks;

// Control setup

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

float temp_1, temp_2;
float target_temp_1, target_temp_2;

float temp_3, temp_4;
float target_temp_3, target_temp_4;

float temp_5, temp_6;
float target_temp_5, target_temp_6;

boolean mlthState, mlttState, hlthState, hlttState;

int mash = 0;
String inputString = "";
String bbuf = "";
String cbuf = "";
boolean stringComplete = false;
long lastupdatestat;


void loop(void) {
  read_temperatures();
  update_pid_1();
  update_pid_2();
  update_status(); 
 
if (stringComplete){

  cbuf = inputString.substring(0,4);
  bbuf = inputString.substring(4);
  long bbuf_int = bbuf.toInt();
  long cbuf_int = cbuf.toInt();  
  
  switch (cbuf_int) {
    
  case 1111: // System will reset AVR if no response is received from brewflowGUI.
    wdt_reset();
    break;  
    
  case 9010:  // Set HLT PID to 'ON' and set temp to bbuf.
    vrg1 = 1;
    target_temp_1 = bbuf_int;
    break;
    
  case 9020: // Set pump 1 to 'ON' and PWM to bbuf.
    pump_set(0, bbuf_int);
    break;
    
  case 9030: // Set pump 1 to 'ON' and PWM to bbuf.
    pump_set(1, bbuf_int);
    break;   

  case 9040:
    pump_set(2, bbuf_int);
    break;

  case 9060:    
    vrg1 = 0;
    break; 

  case 9070:      
    vrg2 = 1;
    target_temp_2 = bbuf_int;
    break; 
     
  case 9080:       
    vrg2 = 0;
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
