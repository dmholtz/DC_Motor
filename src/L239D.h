#ifndef _L293D_H_
#define _L293D_H_

#include "Arduino.h"
#include "DC_Motor.h"

class L293D : public DC_Motor
{
private:
	const uint8_t enable_pin;
	const uint8_t input1_pin;
	const uint8_t input2_pin;
public:
	L293D(const uint8_t enable_pin, const uint8_t input1_pin, const uint8_t input2_pin);
	~L293D();

	virtual void on(uint8_t pwm = 255);
	virtual void off();

	virtual void cw(uint8_t speed = 255);
	virtual void ccw(uint8_t speed = 255);
	virtual void brake();
	virtual void stop();
};

#endif