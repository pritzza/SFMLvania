#include "Keyboard.h"

void KeyBoard::update()
{
	updateKey(w, sf::Keyboard::W);
	updateKey(a, sf::Keyboard::A);
	updateKey(s, sf::Keyboard::S);
	updateKey(d, sf::Keyboard::D);
	updateKey(e, sf::Keyboard::E);
	updateKey(shift, sf::Keyboard::LShift);
	updateKey(space, sf::Keyboard::Space);
}

void KeyBoard::updateKey(Key& k, sf::Keyboard::Key sfk)
{
	if (k.type == KEY_TYPE::TAP && k.active)	// if its a tap key's been used/active, reset active
		k.active = false;

	if (sf::Keyboard::isKeyPressed(sfk))	// is sfml key is pressed, this key is pressed
		k.down = true;
	else
	{
		k.down = false;		// if key isnt pressed, then reset all members
		k.used = false;
		k.active = false;
	}

	if (k.down && !(k.used))	// if the key is down and hasnt been used, set it to active (only has an effect on tap keys)
	{
		k.active = true;
		k.used = true;
	}
}

const bool KeyBoard::isActive(const char c) const
{
	switch (c)
	{
	case 'w':	return w.active;
	case 'a':	return a.active;
	case 's':	return s.active;
	case 'd':	return d.active;
	case 'e':	return e.active;
	case 'S':	return shift.active;
	case ' ':	return space.active;
	}
}