// timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TimerClass
{
 protected:

 public:
	void init();
	void start(uint8_t steptime);
	void pause();
	void reset();
	int timeleft();
	int timepassed();
	bool running();
	int _timer;
};

extern TimerClass StepTimer;

#endif

