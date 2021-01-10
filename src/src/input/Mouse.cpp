#include "Mouse.h"

#include "../util/Window.h"

void Mouse::updateDrag()
{
	int xVel = this->xPos - getPos().x;
	int yVel = this->yPos - getPos().y;

	if (xVel < 0)
		xVel *= -1;
	if (yVel < 0)
		yVel *= -1;

	this->dragDistance = xVel + yVel;

	this->xPos = getPos().x;
	this->yPos = getPos().y;
}

void Mouse::updateCounter()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		++l.heldDuration;
	else
		l.heldDuration = 0;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		++r.heldDuration;
	else
		r.heldDuration = 0;
}

void Mouse::updateClicked()
{
	if (l.heldDuration == 1)
		l.clicked = true;
	else
		l.clicked = false;

	if (r.heldDuration == 1)
		r.clicked = true;
	else
		r.clicked = false;
}

void Mouse::updateHeld()
{
	if (l.heldDuration >= l.heldThreshold || (l.heldDuration && dragDistance > dragThreshold))
		l.held = true;
	else
		l.held = false;

	if (r.heldDuration >= r.heldThreshold || (r.heldDuration && dragDistance > dragThreshold))
		r.held = true;
	else
		r.held = false;
}

void Mouse::update()
{
	updateCounter();
	updateClicked();
	updateDrag();
	updateHeld();
}

const bool Mouse::isClicked(const MOUSE button) const
{
	if (button == MOUSE::LEFT)
		return l.clicked;
  //if (button == MOUSE::RIGHT)
		return r.clicked;
}

const bool Mouse::isHeld(const MOUSE button) const
{
	if (button == MOUSE::LEFT)
		return l.held;
  //if (button == MOUSE::RIGHT)
		return r.held;
}

const sf::Vector2i Mouse::getPos() const
{
	return sf::Mouse::getPosition(this->w);
}