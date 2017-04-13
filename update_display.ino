
#include "brewflow.h"
#include "pins.h"
#include "LiquidCrystal.h"

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

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

int lcd_key = 0;
int adc_key_in = 0;

void update_display(){

  static float mlttemp;

  if (mlttemp != temp[0]) {
    mlttemp = temp[0];
	lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("T: ");
    lcd.print(mlttemp);
	lcd.print("\337");

    lcd.setCursor(0,0);
    lcd.print("Target ");
	if (steptarget == 0) {
	lcd.print("--,-");
	}
	else {
		lcd.print(steptarget);
	}
	lcd.print("\337");

  }


  
}
