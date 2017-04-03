
static const char STR_Beer_[] PROGMEM = "Beer ";
static const char STR_Target_[] PROGMEM = "Target ";
static const char STR_Const_[] PROGMEM = "Const.";
static const char STR_Cool[] PROGMEM = "Cool";
static const char STR_Heat[] PROGMEM = "Heat";
static const char STR_ing_for[] PROGMEM = "ing for";
static const char STR_Wait_to_[] PROGMEM = "Wait to ";
static const char STR__time_left[] PROGMEM = " time left";
//static const char STR_degree_sign[] PROGMEM = \337;
static const char STR_empty_string[] PROGMEM = "";


void update_display(){

  static float mlttemp, target;

  if (mlttemp != temp[0]) {
    mlttemp = temp[0];


    lcd.setCursor(0,1);
    lcd.print("MLT: ");
    lcd.print(mlttemp); 

    lcd.setCursor(0,0);
    lcd.print("Target ");
    lcd.print(steptarget); 

  }


  
}
