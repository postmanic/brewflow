// link.h

#ifndef _LINK_h
#define _LINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "brewflow.h"

void link_init();

void link_receive(String inputString, _brewReceipe &b, _iLock &l, int arr[]);

void link_transmit(int abbs, int nop[]);

void link_send_temp(float arr[], int updateperiod);

void link_send_settings(_pid_params &pidp, _iLock &ilock, int *yk, int updateperiod);

void link_send_receipe(_brewReceipe &b, int updateperiod);

#endif


