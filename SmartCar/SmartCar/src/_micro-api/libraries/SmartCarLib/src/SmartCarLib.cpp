/*
 Name:		SmartCarLib.cpp
 Created:	7/8/2016 5:40:16 PM
 Author:	snackk
*/

#include "SmartCarLib.h"

SmartCar::SmartCar(int l_pin1, int l_pin2, int l_pwm_pin, int r_pin1, int r_pin2, int r_pwm_pin) {
	_l_pin1 = l_pin1;
	_l_pin2 = l_pin2;
	_l_pwm_pin = l_pwm_pin;
	_r_pin1 = r_pin1;
	_r_pin2 = r_pin2;
	_r_pwm_pin = r_pwm_pin;

	//Define L298N Dual H-Bridge Motor Controller Pins
	pinMode(_l_pin1, OUTPUT);
	pinMode(_l_pin2, OUTPUT);
	pinMode(_l_pwm_pin, OUTPUT);

	pinMode(_r_pin1, OUTPUT);
	pinMode(_r_pin2, OUTPUT);
	pinMode(_r_pwm_pin, OUTPUT);

	_state = stop;
	Serial.begin(9600);
}

void SmartCar::handleCar(String data_b) {
	/*DEBUG ONLY
	Speed not working properly
	*/
	if (data_b.charAt(0) == 'S') {
		char sp[5], data[3];
		strcpy(sp, data_b.c_str());
		int speed;
		for (int i = 0; i < 3; i++) {
			int offset = 2 + i;
			data[i] = sp[offset];
		}
		sscanf(data, "%d", &speed);
		//_speed = speed;
		Serial.println("speed: " + speed);

	}

	if (data_b.equals("F\n")) {
		if (_state != forward) {
			doForward();
			_state = forward;
		}
		else {
			doStop();
			_state = stop;
		}
	}
	else {
		if (data_b.equals("B\n")) {
			if (_state != reverse) {
				doReverse();
				_state = reverse;
			}
			else {
				doStop();
				_state = stop;
			}
		}
		else {
			if (data_b.equals("L\n")) {
				if (_state != left) {
					doLeftTurn();
					_state = left;
				}
				else {
					doStop();
					_state = stop;
				}
			}
			else {
				if (data_b.equals("R\n")) {
					if (_state != right) {
						doRightTurn();
						_state = right;
					}
					else {
						doStop();
						_state = stop;
					}
				}
			}
		}
	}
}

//---FORWARD---//
void SmartCar::doForward() {
	doLeftForward();
	doRightForward();
}

void SmartCar::doLeftForward() {
	//Left Motors
	analogWrite(_l_pwm_pin, _speed);
	digitalWrite(_l_pin1, LOW);
	digitalWrite(_l_pin2, HIGH);
}

void SmartCar::doRightForward() {
	//Right Motors
	analogWrite(_r_pwm_pin, _speed);
	digitalWrite(_r_pin1, LOW);
	digitalWrite(_r_pin2, HIGH);
}

//TURN LEFT
void SmartCar::doLeftTurn() {
	/*if(state == forward){
	}
	if(state == reverse){

	}*/
	doLeftReverse();
	doRightForward();
}

//TURN RIGHT
void SmartCar::doRightTurn() {
	/*if(state == forward){
	}
	if(state == reverse){

	}*/
	doRightReverse();
	doLeftForward();
}

//---STOP---//
void SmartCar::doStop() {
	doStopLeft();
	doStopRight();
}

void SmartCar::doStopLeft() {
	analogWrite(_l_pwm_pin, 0);
	digitalWrite(_l_pin1, LOW);
	digitalWrite(_l_pin2, HIGH);
}

void SmartCar::doStopRight() {
	analogWrite(_r_pwm_pin, 0);
	digitalWrite(_r_pin1, LOW);
	digitalWrite(_r_pin2, HIGH);
}

//---REVERSE---//    
void SmartCar::doReverse() {
	doLeftReverse();
	doRightReverse();
}

void SmartCar::doLeftReverse() {
	analogWrite(_l_pwm_pin, _speed);
	digitalWrite(_l_pin1, HIGH);
	digitalWrite(_l_pin2, LOW);
}

void SmartCar::doRightReverse() {
	analogWrite(_r_pwm_pin, _speed);
	digitalWrite(_r_pin1, HIGH);
	digitalWrite(_r_pin2, LOW);
}

