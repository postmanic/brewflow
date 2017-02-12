/*
 * Copyright 2015 brewflow/Lars Rosenskjold
 *
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

// Needs more elegant control of sensors

 void read_temperatures(){
  sensors.requestTemperatures(); 
  temp1 = sensors.getTempCByIndex(0);
  delay(2);
  temp2 = sensors.getTempCByIndex(1); 
  delay(2);
  temp3 = sensors.getTempCByIndex(2);
  delay(2);
  temp4 = sensors.getTempCByIndex(3); 
  delay(2);
}
