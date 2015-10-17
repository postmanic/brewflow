/*
  BrewFlow

  modified 16 october 2015
  by Lars Rosenskjold Jacobsen
  
  Opbygges sådan at styringen er generisk.
  
  Gryde 1
  1 x heat PID (pin 9)
  2 x temp (pin 3)
  2 x pumpe PWM (pin 5, 6)
  
  Gryde 2
  1 x heat PID (pin 10)
  2 x temp (pin 3)
  1 x pumpe PWM (pin 11)
  
  Gryde 3
  2 x temp (pin 3)
  
  PWM PIN 3,5,6,9,10,11
  
 */

#include <OneWire.h>
#include <DallasTemperature.h>

// Hardware setup

#define One_Wire_Bus (3)  // Thermometers.
#define pump_1 (5)        // Pumpe 1 PWM output.
#define pump_2 (6)        // Pumpe 2 PWM output.
#define pump_3 (11)       // Pumpe 3 PWM output.
#define heat_1 (9)        // MLT heater [mlth].
#define heat_2 (10)       // HLT heater [hlth].

#define pump_1_ctrl (4)   // Pump 1 control output.
#define pump_2_ctrl (7)   // Pump 2 control output.
#define pump_3_ctrl (8)   // Pump 3 control output.

double pump_1_speed;
double pump_2_speed;
double pump_3_speed;
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

double kc = 1.2, ti = 2.5, td = 0.5, ts = 5;
double k_lpf, k0, k1, k2, k3, lpf1, lpf2, pp, pi, pd;
static double ek_1, ek_2, xk_1, xk_2, yk_1, yk_2, lpf_1, lpf_2;
boolean vrg = false;
int ts_ticks;

// Control setup

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

float temp_1, temp_2;
float target_temp_1, target_temp_2;

float temp_3, temp_4;
float target_temp_3, target_temp_4;

float temp_5, temp_6;
float target_temp_5, target_temp_6;

boolean mlthState, mlttState, hlthState, hlttState, pump1state, pump2state;

int mash = 0;
String inputString = "";
String bbuf = "";
boolean stringComplete = false;
long lastupdatestat;


void loop(void) {
  Aflaes_Temperaturer();
  Opdater_PID();
  Opdater_Status(); 
 
if (stringComplete){
  
  if (inputString.startsWith("9030", 0)){
    bbuf = inputString.substring(4);
    pump_2_speed = bbuf.toInt();
    if (pump_2_speed > 100) {
      pump_2_speed = 100;
    }
    if (pump_2_speed > 0) {
    pump_2_speed = (pump_2_speed / 100) * 255;
    analogWrite(pump_2, pump_2_speed);
    pump2state = HIGH;
    }
    else {
    analogWrite(pump_2, pump_2_speed);
    pump2state = LOW;
    }
    
  } 
  
  if (inputString.startsWith("9020", 0)){
    bbuf = inputString.substring(4);
    pump_1_speed = bbuf.toInt();
    if (pump_1_speed > 100) {
      pump_1_speed = 100;
    }
    if (pump_1_speed > 0) {
    pump_1_speed = (pump_1_speed / 100) * 255;
    analogWrite(pump_1, pump_1_speed);
    pump1state = HIGH;
    }
    else {
    analogWrite(pump_1, pump_1_speed);
    pump1state = LOW;
    }
    
  }
  if (inputString.startsWith("9010", 0)){
    bbuf = inputString.substring(4);
    mash = bbuf.toInt();
    vrg = 1;
    target_temp_1 = mash;
  
  }  
 						
  inputString = "";
  stringComplete = false;
}


}
