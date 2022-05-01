#include "Button.h"

void Button::update(const bool down)
{
	if		(state == BUTTON_STATE::SLEEP    &&  down)		state = BUTTON_STATE::TAPPED;
	else if (state == BUTTON_STATE::TAPPED   &&  down)		state = BUTTON_STATE::HELD;
	else if (state == BUTTON_STATE::HELD	  && !down)		state = BUTTON_STATE::RELEASED;
	else if (state == BUTTON_STATE::RELEASED && !down)		state = BUTTON_STATE::SLEEP;
}

const bool Button::isTapped() const
{
	if (state == BUTTON_STATE::TAPPED)
		return true;
	return false;
}

const bool Button::isHeld() const
{
	if (state == BUTTON_STATE::HELD)
		return true;
	return false;
}
const bool Button::isReleased() const
{
	if (state == BUTTON_STATE::RELEASED)
		return true;
	return false;
}

const bool Button::isSleep() const
{
	if (state == BUTTON_STATE::SLEEP)
		return true;
	return false;
}
