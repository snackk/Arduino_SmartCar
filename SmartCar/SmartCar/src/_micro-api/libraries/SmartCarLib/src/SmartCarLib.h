/*
 Name:		SmartCarLib.h
 Created:	7/8/2016 5:40:16 PM
 Author:	snackk
*/

#ifndef _SmartCarLib_h
#define _SmartCarLib_h

#include "Arduino.h"

class SmartCar {

public:
	SmartCar(int l_pin1, int l_pin2, int l_pwm_pin, int r_pin1, int r_pin2, int r_pwm_pin);
	void handleCar(String data_b);
private:
	int _l_pin1, _l_pin2, _l_pwm_pin, _r_pin1, _r_pin2, _r_pwm_pin;

	enum state_t {
		forward,
		reverse,
		left,
		right,
		stop
	};

	state_t _state;

	void doForward();
	void doLeftForward();
	void doRightForward();
	void doLeftTurn();
	void doRightTurn();
	void doStop();
	void doStopLeft();
	void doStopRight();
	void doReverse();
	void doLeftReverse();
	void doRightReverse();
};


#endif

