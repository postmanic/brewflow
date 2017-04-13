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

#include "Arduino.h"
#include "brewflow.h"
#include "timer.h"
#include "Temperatures.h"
#include "display.h"
#include "pins.h"
#include "Link.h"
#include "pid.h"

int lcd_key = 0;
int adc_key_in = 0;
byte pumpspeed;   // ( 0 - 255 )
int yk;
float temp[5];
byte step_x;
int rxaaray[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int pumpvent, pumptimer, wspeed1;
String inputString = "";
boolean stringComplete = false;

_brewReceipe	brewReceipe;
_iLock			iLock;
_pid_params		pid_params;


void setup() {
	display.init();
	Serial.begin(57600);
	analogReference(EXTERNAL);
	pinMode(HEATCTRLPIN, OUTPUT);
	pinMode(PUMP1CTRLPIN, OUTPUT);
	analogWrite(HEATCTRLPIN, LOW);
	Serial.begin(LINK_SPEED);
	Temperatures_init();
	StepTimer.start(0);
}

void loop(void) {

	//lcd_key = read_LCD_buttons();  // read the buttons
	Temperatures_update(temp);
	PID_update(temp, iLock.vrg, &yk, pid_params);
	display.printTemperature(temp[0]);
	//lcddisplay.printPumpState();
	//update_pump();
	//update_display();
	link_send_temp(temp, 1);
	link_send_receipe(brewReceipe, 1);
	link_send_settings(pid_params, iLock, &yk, 1);

	if (stringComplete) {
		link_receive(inputString, brewReceipe, iLock, rxaaray);
		inputString = "";
		stringComplete = false;
		}
	
	switch (step_x) {

	case 1:

		if (iLock.vrg == false) {
			iLock.vrg = true;
		}

		if ((millis() / 1000 < (pumptimer + 5)) || (millis() / 1000 > (pumptimer + 10) && millis() / 1000 < (pumptimer + 15))) {
			if (iLock.pumpstate == 0) {
				iLock.pumpstate = true;
				wspeed1 = 60;
			}
		}
		else {
			if (iLock.pumpstate == 1) {
				iLock.pumpstate = false;
				wspeed1 = 0;
				pumpvent++;
			}
		}

		if (temp[0] >= pid_params.steptarget && iLock.water == true && pumpvent == 2) {
			step_x = 2;
		}
		break;

		//
		// Der er ventileret og Mash In temperatur er nået, nu skal der tilsættes malt og omrøres.
		// Når der er tilsat malt og omrørt skal bruger acceptere.
		// Derefter videre til næste step.
		//

	case 2: // MashIn grain added.
		if (iLock.water == true && iLock.grain == true) {
			pid_params.steptimer = (millis() / 1000) + (60 * brewReceipe.step1target);   // step 1        
			pid_params.steptarget = brewReceipe.step1target;
			step_x = 3;
			iLock.pumpstate = true;
			wspeed1 = 30;
		}
		break;

	case 3: // Step 1

		if (pid_params.steptimer) {
			// Timer running
		}
		else { // Step 1 done
			step_x = 4; // Next step, Step 2    
			pid_params.steptimer = millis() / 1000 + (60 * brewReceipe.step2time);
			pid_params.steptarget = brewReceipe.step2target;
			iLock.vrg = true;
			delay(50);
		}

		break;

	case 4: // Step 2.
		if (millis() / 1000 < (pid_params.steptimer)) {
			// Timer running
		}
		else {
			// Step 2 done
			step_x = 5;
			pid_params.steptimer = millis() / 1000 + (60 * brewReceipe.step3time);
			pid_params.steptarget = brewReceipe.step3target;
			iLock.vrg = true;
			delay(50);
		}

		break;

	case 5: // Step 3.
		if (millis() / 1000 < (pid_params.steptimer)) {
			// Timer running
		}
		else {
			// Step 3 done
			step_x = 6;
			pid_params.steptimer = millis() / 1000 + (60 * brewReceipe.step4time);
			pid_params.steptarget = brewReceipe.step4target;
			iLock.vrg = true;
			delay(50);

		}
		break;

	case 6: // Step 4.
		if (millis() / 1000 < (pid_params.steptimer)) {
			// Timer running
		}
		else {
			// Step 4 done
			step_x = 7;
			pid_params.steptimer = millis() / 1000 + (60 * brewReceipe.mashouttime);
			pid_params.steptarget = brewReceipe.mashouttarget;
			iLock.vrg = true;
			delay(50);
		}
		break;

	case 7: // Mash Out.
		if (iLock.mashout == false) {
			// Done mashout
		}
		else {
			// MashOut done, next start boil
			step_x = 8;
			pid_params.steptimer = millis() / 1000 + (60 * brewReceipe.boiltime);
			pid_params.steptarget = brewReceipe.boiltarget;
			iLock.vrg = true;
			delay(50);
		}
		break;

	case 8: // Boil.
		if (millis() / 1000 < (pid_params.steptimer)) {
			iLock.pumpstate = false;
			wspeed1 = 60;
		}
		else {
			// Boil done, finished.
			iLock.vrg = false;
			step_x = 9;
			delay(50);
		}
		break;

	case 9: // Done.

		iLock.vrg = false;
		iLock.pumpstate = false;
		wspeed1 = 0;

		break;


	default: // system is reset and we are waiting for user to acknowledge that theres is water in tank.We are also waiting for receipe to be set
		if (iLock.water == true && brewReceipe.mashintarget != 0 && brewReceipe.step1target != 0 && brewReceipe.step1time != 0) {
			pid_params.steptarget = brewReceipe.mashintarget;
			//StepTimer.reset();
			//StepTimer.start(mybrew.mashintime);
			iLock.vrg = true;
			step_x = 1;
		}
		break;
	}
}

void serialEvent() {
	static int a = 0;
	while (Serial.available()) {
		int inChar = Serial.read();
		if (inChar == ',') {
			rxaaray[a] = inputString.toInt();
			inputString = "";
			a++;
		}
		else {
			inputString += (char)inChar;
		}
		if (inChar == '\n') {
			stringComplete = true;
			rxaaray[a] = inputString.toInt();
			inputString = "";
			a++;
		}
	}
}