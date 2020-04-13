#include "DRV.h"

DRV::DRV(const uint8_t enable_pin, const uint8_t phase_pin, const uint8_t mode_pin)
	: enable_pin{enable_pin}, phase_pin{phase_pin}, mode_pin{mode_pin}
{
	pinMode(enable_pin, OUTPUT);
	digitalWrite(enable_pin, LOW);
	pinMode(phase_pin, OUTPUT);
	digitalWrite(phase_pin, LOW);
	pinMode(mode_pin, OUTPUT);
	digitalWrite(mode_pin, HIGH);
}

// DRV chip without mode_pin
DRV::DRV(const uint8_t enable_pin, const uint8_t phase_pin)
	: enable_pin{enable_pin}, phase_pin{phase_pin}, mode_pin{}
{
	pinMode(enable_pin, OUTPUT);
	digitalWrite(enable_pin, LOW);
	pinMode(phase_pin, OUTPUT);
	digitalWrite(phase_pin, LOW);
	// mode_pin is pulled on high by hardware
}

DRV::~DRV()
{
	this->stop();
}

void DRV::on(const uint8_t pwm)
{
	this->cw(pwm);
}

void DRV::off()
{
	this->stop();
}

void DRV::cw(const uint8_t speed)
{
	this->state = DC_Motor_State::CLOCKWISE;
	this->speed = speed;

	digitalWrite(phase_pin, LOW);
	analogWrite(enable_pin, speed);
}

void DRV::ccw(const uint8_t speed)
{
	this->state = DC_Motor_State::COUNTERCLOCKWISE;
	this->speed = speed;

	digitalWrite(phase_pin, HIGH);
	analogWrite(enable_pin, speed);
}

void DRV::stop()
{
	this->state = DC_Motor_State::STOPPED;
	this->speed = speed;

	digitalWrite(phase_pin, LOW);
	analogWrite(enable_pin, LOW);
}

void DRV::brake()
{
	// Braking is not supported, stop motor instead
	this->stop();
}