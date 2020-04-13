#include "L293D.h"

L293D::L293D(const uint8_t enable_pin, const uint8_t input1_pin, const uint8_t input2_pin)
	: enable_pin{enable_pin}, input1_pin{input1_pin}, input2_pin{input2_pin}
{
	pinMode(enable_pin, OUTPUT);
	digitalWrite(enable_pin, LOW);
	pinMode(input1_pin, OUTPUT);
	digitalWrite(input1_pin, LOW);
	pinMode(input2_pin, OUTPUT);
	digitalWrite(input2_pin, LOW);
}

L293D::~L293D()
{
	this->stop();
}

void L293D::on(const uint8_t pwm)
{
	this->cw(pwm);
}

void L293D::off()
{
	this->stop();
}

void L293D::cw(const uint8_t speed)
{
	this->state = DC_Motor_State::CLOCKWISE;
	this->speed = speed;

	digitalWrite(input1_pin, HIGH);
	digitalWrite(input2_pin, LOW);
	analogWrite(enable_pin, speed);
}

void L293D::ccw(const uint8_t speed)
{
	this->state = DC_Motor_State::COUNTERCLOCKWISE;
	this->speed = speed;

	digitalWrite(input1_pin, LOW);
	digitalWrite(input2_pin, HIGH);
	analogWrite(enable_pin, speed);
}

void L293D::stop()
{
	this->state = DC_Motor_State::STOPPED;
	this->speed = speed;

	digitalWrite(input1_pin, LOW);
	digitalWrite(input2_pin, LOW);
	analogWrite(enable_pin, LOW);
}

void L293D::brake()
{
	this->state = DC_Motor_State::BRAKING;
	this->speed = speed;

	digitalWrite(input1_pin, HIGH);
	digitalWrite(input2_pin, HIGH);
	analogWrite(enable_pin, HIGH);
}