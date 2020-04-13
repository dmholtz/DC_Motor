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
	virtual ~DRV();

	virtual void on(uint8_t pwm = 255) override;
	virtual void off() override;

	virtual void cw(uint8_t speed = 255) override;
	virtual void ccw(uint8_t speed = 255) override;
	virtual void brake() override;
	virtual void stop() override;
};

#endif