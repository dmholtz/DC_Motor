#include "DC_Motor.h"

DC_Motor::DC_Motor()
	: speed{0}, state{DC_Motor_State::STOPPED}
{
}

DC_Motor_State DC_Motor::get_state() const
{
	return this->state;
}

uint8_t DC_Motor::get_speed() const
{
	return this->speed;
}