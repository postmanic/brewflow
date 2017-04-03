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
 
#ifndef lcdDisplay_h
#define lcdDisplay_h

#include "Arduino.h"

class lcdDisplay
{
  public:
  
  void init(void);
  void printTemperature(int16_t temp);
  void printTemperatureAt(uint8_t x, uint8_t y, int16_t temp);
  void printTargetTemperature(int16_t temp);
  void printTargetTemperatureAt(uint8_t x, uint8_t y, int16_t temp);
  void printPumpState(void);
  void printPumpStateAt(uint8_t x, uint8_t y, char* text);  
  void printStepState(void);
  void printStepStateAt(uint8_t x, uint8_t y, char* text);   
  void printMLTState(void);
  void printMLTStateAt(uint8_t x, uint8_t y, char* text);    
  void printAt(uint8_t x, uint8_t y, char* text);

};

#endif
