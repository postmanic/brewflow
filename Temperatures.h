/*


Class Temperatur




*/


// DSTemperatures.h

#ifndef _DSTEMPERATURES_h
#define _DSTEMPERATURES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


void	Temperatures_init();
void	Temperatures_update(float arr[]);
int		Temperatures_sensorCount();


#endif

