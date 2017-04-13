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

#include "pid.h"

void PID_update(float arr[], bool vrg, int *yk, _pid_params &p)
{
	static int _PID_LAST_UPDATE;
	static double xk_1, xk_2;
	float pp, pi, pd;

	if (millis() / 1000 >= (int)(_PID_LAST_UPDATE + (int)PID_TS)) {
		
		// DEBUG 
		Serial.println("Timer drop!");
		Serial.println(millis() / 1000);
		Serial.println((int)PID_TS);
		Serial.println((int)_PID_LAST_UPDATE + (int)PID_TS);
		// DEBUG

		_PID_LAST_UPDATE = millis() / 1000;
		if (vrg) {

			// DEBUG
			Serial.println("PID active!");
			// DEBUG

			pp = PID_KC * (xk_1 - arr[0]);
			pi = (PID_KC * PID_TS / PID_TI) * (p.steptarget - arr[0]);
			pd = (PID_KC * PID_TD / PID_TS) * (2.0 * xk_1 - arr[0] - xk_2);
			*yk += pp + pi + pd;
		}
		else {
			*yk = pp = pi = pd = 0.0;
		}
		xk_2 = xk_1;
		xk_1 = arr[0];
		if (*yk > 100) {
			*yk = 100;
		}
		else if (*yk < 0) {
			*yk = 0;
		}
	}
}