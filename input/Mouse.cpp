#include "Mouse.h"

#include "../util/Window.h"

void Mouse::update()
{
	left.update(sf::Mouse::isButtonPressed(sf::Mouse::Left));
	middle.update(sf::Mouse::isButtonPressed(sf::Mouse::Middle));
	right.update(sf::Mouse::isButtonPressed(sf::Mouse::Right));
}

const sf::Vector2i Mouse::getPos() const
{
	return sf::Mouse::getPosition(this->w);
}