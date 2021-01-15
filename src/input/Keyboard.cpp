#include "Keyboard.h"

void KeyBoard::update()
{
	w.update(sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	a.update(sf::Keyboard::isKeyPressed(sf::Keyboard::A));
	s.update(sf::Keyboard::isKeyPressed(sf::Keyboard::S));
	d.update(sf::Keyboard::isKeyPressed(sf::Keyboard::D));
	e.update(sf::Keyboard::isKeyPressed(sf::Keyboard::E));
	shift.update(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift));
	space.update(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
}