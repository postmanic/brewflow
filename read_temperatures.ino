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



// Needs more elegant control of sensors

void update_temperatures(){
  sensors.requestTemperatures();
  temp[1] = sensors.getTempC(T1);
  delay(2);
  temp[1] = debugtemp1;
  temp[2] = sensors.getTempC(T2);
  delay(2);
  temp[2] = debugtemp2;
}
