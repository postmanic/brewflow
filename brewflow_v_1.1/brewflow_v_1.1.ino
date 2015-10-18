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

boolean mlthState, mlttState, hlthState, hlttState;

int mash = 0;
String inputString = "";
String bbuf = "";
String cbuf = "";
boolean stringComplete = false;
long lastupdatestat;


void loop(void) {
  Aflaes_Temperaturer();
  Opdater_PID();
  Opdater_Status(); 
 
if (stringComplete){

  cbuf = inputString.substring(0,4);
  bbuf = inputString.substring(4);
  
  Serial.println(cbuf+" / "+bbuf);
   
  if (inputString.startsWith("9010", 0)){
    bbuf = inputString.substring(4);
    mash = bbuf.toInt();
    vrg = 1;
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
    vrg = 1;
    target_temp_1 = mash;
  
  }   						
  inputString = "";
  stringComplete = false;
}


}
