#ifndef _DRV_H_
#define _DRV_H_

#include "Arduino.h"
#include "DC_Motor.h"

class DRV : public DC_Motor
{
private:
	const uint8_t enable_pin;
	const uint8_t phase_pin;
	const uint8_t mode_pin;
public:
	DRV(const uint8_t enable_pin, const uint8_t phase_pin, const uint8_t mode_pin);
	DRV(const uint8_t enable_pin, const uint8_t phase_pin);
	~DRV() = default;

	virtual void on(uint8_t pwm = 255);
	virtual void off();

	virtual void cw(uint8_t speed = 255);
	virtual void ccw(uint8_t speed = 255);
	virtual void brake();
	virtual void stop();
};

#endif