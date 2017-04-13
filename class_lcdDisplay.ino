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
 


class lcdDisplay
{
  public:
  
  static void init(void);
  static void printTemperature(int16_t temp);
  static void printTemperatureAt(uint8_t x, uint8_t y, int16_t temp);
  static void printTargetTemperature(int16_t temp);
  static void printTargetTemperatureAt(uint8_t x, uint8_t y, int16_t temp);
  static void printPumpState(void);
  static void printPumpStateAt(uint8_t x, uint8_t y, char* text);  
  static void printStepState(void);
  static void printStepStateAt(uint8_t x, uint8_t y, char* text);   
  static void printMLTState(void);
  static void printMLTStateAt(uint8_t x, uint8_t y, char* text);    
  static void printAt(uint8_t x, uint8_t y, char* text);

};

void lcdDisplay::init(void)
{
	lcd.begin(16, 2);
	lcd.setCursor(2, 0);
	lcd.print("brewflow 0.5");
	lcd.setCursor(7, 1);
	lcd.print("welcome");
	delay(2000);
}

void lcdDisplay::printTemperature(int16_t temp)
{
}

void lcdDisplay::printTemperatureAt(uint8_t x, uint8_t y, int16_t temp)
{
}

void lcdDisplay::printTargetTemperature(int16_t temp)
{
}

void lcdDisplay::printTargetTemperatureAt(uint8_t x, uint8_t y, int16_t temp)
{
}

void lcdDisplay::printPumpState(void)
{
}

void lcdDisplay::printPumpStateAt(uint8_t x, uint8_t y, char * text)
{
}

void lcdDisplay::printStepState(void)
{
}

void lcdDisplay::printStepStateAt(uint8_t x, uint8_t y, char * text)
{
}

void lcdDisplay::printMLTState(void)
{
}

void lcdDisplay::printMLTStateAt(uint8_t x, uint8_t y, char * text)
{
}

void lcdDisplay::printAt(uint8_t x, uint8_t y, char * text)
{
}

lcdDisplay lcddisplay;