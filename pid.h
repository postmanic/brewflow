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


#ifndef _PID_h
#define _PID_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "brewflow.h"

void PID_update(float arr[], bool vrg, int *yk, _pid_params &p);

#endif







