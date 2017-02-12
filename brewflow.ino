/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
 * 
 * This file is part of brewflow.
 *
 * Mash control and ferment control.
 *
 * For Arduino UNO
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
// Uses 4 x DS1820B 2 for each tank. 1 top (mash) and 1 bottom (circulating)
// Uses DFROBOT L298P 2A motor shield
// Uses 2 x SSR 40A for PID controlled PWM output to heaters MLT and HLT

#define One_Wire_Bus (3)  // Thermometers.
#define pump1ctrl (4)     // Pump 1 control.
#define pump1pwm  (5)     // Pump 1 PWM.
#define pump2ctrl (6)     // Pump 2 control.
#define pump2pwm  (7)     // Pump 2 PWM.
#define heat1 (9)         // MLT heater PWM.
#define heat2 (10)        // HLT heater PWM.
//#define SECS_PER_MIN  (60UL)
//#define SECS_PER_HOUR (3600UL)
//#define SECS_PER_DAY  (SECS_PER_HOUR * 24L)
//#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)
//#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN)
//#define numberOfHours(_time_) (( _time_% SECS_PER_DAY) / SECS_PER_HOUR)
//#define elapsedDays(_time_) ( _time_ / SECS_PER_DAY)
#define TWENTY_SECONDS (400)
#define TEN_SECONDS (200)
#define FIVE_SECONDS (100)
#define ONE_SECOND (20)
#define T_50MSEC (50)
#define GMA_HLIM (100.0)
#define GMA_LLIM (0.0)

// PID setup

double kc = 1.2, ti = 2.5, td = 0.5, ts = 5, k_lpf, k0, k1, k2, k3, lpf1, lpf2, pp, pi, pd;
double temp1, temp2, temp3, temp4, target, pump1speed, pump2speed, intensity, steptimer;
static double ek_1, ek_2, xk_1, xk_2, yk_1, yk_2, lpf_1, lpf_2;
boolean stringComplete = false, ilock = false, vrg = false, pump1state, pump2state, mlthState, mlttState, hlthState, hlttState;
int mash = 0, commands = 0, ticks;
String inputString = "", bbuf = "", cbuf = "";
long lastupdatestat, lastupdateui;

// Control setup

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

void loop(void) {

  read_temperatures();
  update_pid();
  update_ui(10000);
  send_status(10000);  
  user_input();
 
}
