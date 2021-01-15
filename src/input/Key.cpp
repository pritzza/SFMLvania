#include "Key.h"

void Key::update(const bool down)
{
	if		(state == KEY_STATE::SLEEP    &&  down)		state = KEY_STATE::TAPPED;
	else if (state == KEY_STATE::TAPPED   &&  down)		state = KEY_STATE::HELD;
	else if (state == KEY_STATE::HELD	  && !down)		state = KEY_STATE::RELEASED;
	else if (state == KEY_STATE::RELEASED && !down)		state = KEY_STATE::SLEEP;
}

const bool Key::isTapped() const
{
	if (state == KEY_STATE::TAPPED)
		return true;
	return false;
}

const bool Key::isHeld() const
{
	if (state == KEY_STATE::HELD)
		return true;
	return false;
}
const bool Key::isReleased() const
{
	if (state == KEY_STATE::RELEASED)
		return true;
	return false;
}

const bool Key::isSleep() const
{
	if (state == KEY_STATE::SLEEP)
		return true;
	return false;
}
