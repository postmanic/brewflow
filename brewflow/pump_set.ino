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

void pump_set(int wpump, int wspeed){
  
    if (wspeed > 100) {
      wspeed = 100;
    }
    if (wspeed > 0) {
      
    pumpspeed[wpump] = wspeed * 255 / 100;

    //Serial.println(test);
    
    analogWrite(pump[wpump], wspeed);
    pumpstate[wpump] = HIGH;
    }
    else {
    analogWrite(pump[wpump], 0);
    pumpspeed[wpump] = 0;
    pumpstate[wpump] = LOW;
    } 
}
