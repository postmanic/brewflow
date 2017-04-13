// 
// 
// 

#include "timer.h"

void TimerClass::init()
{


}

void TimerClass::start(uint8_t steptime)
{
	static int timer;
	timer = millis() / 1000 + 60 * steptime;
}

void TimerClass::pause()
{
}

void TimerClass::reset()
{
}

int TimerClass::timeleft()
{
	return 0;
}

int TimerClass::timepassed()
{
	return _timer - millis() / 1000;
}

bool TimerClass::running()
{
	return true;
}


TimerClass StepTimer;

