/*
  BrewFlow

  by Lars Rosenskjold Jacobsen
  
  PID author: E. vd Logt.
  
  
 */

#include <OneWire.h>
#include <DallasTemperature.h>

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
int v1ts_ticks;
int v2ts_ticks;
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
  Aflaes_Temperaturer();
  update_pid_1();
  update_pid_2();
  Opdater_Status(); 
 
if (stringComplete){

  cbuf = inputString.substring(0,4);
  bbuf = inputString.substring(4);
     
  if (inputString.startsWith("9010", 0)){
    mash = bbuf.toInt();
    vrg1 = 1;
    target_temp_1 = mash;
  }  
   if (inputString.startsWith("9020", 0)){
      pumpset(0, bbuf.toInt());
   }  
  
   if (inputString.startsWith("9030", 0)){
      pumpset(1, bbuf.toInt());
   }   
   
   if (inputString.startsWith("9040", 0)){
      pumpset(2, bbuf.toInt());
   } 
   
  if (inputString.startsWith("9050", 0)){
    bbuf = inputString.substring(4);
    mash = bbuf.toInt();
    vrg1 = 1;
    target_temp_1 = mash;
   }



   if (inputString.startsWith("9060", 0)){
      vrg1 = 0;
   } 
 
  if (inputString.startsWith("9070", 0)){
    bbuf = inputString.substring(4);
    mash = bbuf.toInt();
    vrg2 = 1;
    target_temp_2 = mash;
   }   
     if (inputString.startsWith("9080", 0)){
      vrg2 = 0;
   }  
   
   
   						
  inputString = "";
  stringComplete = false;
}


}
