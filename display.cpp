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

#include "display.h"
#include "LiquidCrystal.h"
#include "pins.h"

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

void DisplayClass::init(void)
{
	lcd.begin(16, 2);
	lcd.setCursor(1, 0);
	lcd.print(String("brewflow ") + String(BREWFLOW_VERSION));
	lcd.setCursor(7, 1);
	lcd.print("welcome");
	delay(3000);
	lcd.clear();
}

void DisplayClass::clearLine(uint8_t line)
{
	lcd.setCursor(0, line);
	lcd.print(String("                "));
}



void DisplayClass::printTemperature(float temp) 
{
	lcd.setCursor(2, 0);
	if (temp != -127) {
		lcd.print(String("T1: ") + String(temp) + String("\337"));
	}
	else {
		lcd.print(String("T1: ") + String("error"));
	}
	lcd.setCursor(2, 1);
	if (temp != -127) {
		lcd.print(String("T2: ") + String(temp) + String("\337"));
	}
	else {
		lcd.print(String("T2: ") + String("error"));
	}
}

void DisplayClass::printTemperatureAt(uint8_t x, uint8_t y, int16_t temp)
{
	lcd.setCursor(x, y);
	lcd.print(String("T1: ") + String(temp) + String("\337"));
}

void DisplayClass::printTargetTemperature(int16_t temp)
{
}

void DisplayClass::printTargetTemperatureAt(uint8_t x, uint8_t y, int16_t temp)
{
}

void DisplayClass::printPumpState(void)
{
}

void DisplayClass::printPumpStateAt(uint8_t x, uint8_t y, char * text)
{
}

void DisplayClass::printStepState(void)
{
}

void DisplayClass::printStepStateAt(uint8_t x, uint8_t y, char * text)
{
}

void DisplayClass::printMLTState(void)
{
}

void DisplayClass::printMLTStateAt(uint8_t x, uint8_t y, char * text)
{
}

void DisplayClass::printAt(uint8_t x, uint8_t y, char * text)
{
}


DisplayClass display;

