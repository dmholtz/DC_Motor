/** Arduino library to conveniently control DC Motors using different driver ICs.
 * 
 * by dmholtz
 * April, 2020 
 * 
 **/

#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include "Arduino.h"

enum DC_Motor_State {
	STOPPED = 0,
	BRAKING = 0,
	COUNTERCLOCKWISE = 1,
	CLOCKWISE = -1,
};

class DC_Motor
{
protected:
	uint8_t speed;
	DC_Motor_State state;

public:
	DC_Motor();
	~DC_Motor() = default;

	virtual void on(const uint8_t pwm = 255) = 0;
	virtual void off() = 0;

	virtual void cw(const uint8_t speed = 255) = 0;		// turns the motor clockwise
	virtual void ccw(const uint8_t speed = 255) = 0;	// turns the motor counterclockwise
	virtual void brake() = 0;
	virtual void stop() = 0;

	virtual uint8_t get_speed() const final;
	virtual DC_Motor_State get_state() const final;
};

#endif