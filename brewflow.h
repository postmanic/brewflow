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

#ifndef _BREWFLOW_h
#define _BREWFLOW_h

#pragma once

#ifndef LINK_SPEED
#define LINK_SPEED 57600
#endif

#ifndef BREWFLOW_DEBUG
#define BREWFLOW_DEBUG false
#endif

#ifndef BREWFLOW_VERSION
#define BREWFLOW_VERSION 0.42
#endif

#ifndef PID_STATICS
#define PID_TD 0.5
#define PID_TS 20
#define PID_TI 2.5
#define PID_KC 1.2
#endif

struct _pid_params {
	int steptarget;
	byte steptimer;
};

struct _brewReceipe {

	int mashintime;
	int step1time;
	int step2time;
	int step3time;
	int step4time;
	int mashouttime;
	int boiltime;
	int	mashintarget;
	int step1target;
	int step2target;
	int step3target;
	int step4target;
	int mashouttarget;
	int boiltarget;

};

struct _iLock {

	bool water = false;
	bool grain = false;
	bool mashout = false;
	bool vrg = false;
	bool pumpstate = false;

};

#endif