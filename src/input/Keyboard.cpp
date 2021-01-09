#include "Keyboard.h"

void KeyBoard::update()
{
	updateKey(w, sf::Keyboard::W);
	updateKey(a, sf::Keyboard::A);
	updateKey(s, sf::Keyboard::S);
	updateKey(d, sf::Keyboard::D);
	updateKey(shift, sf::Keyboard::LShift);
	updateKey(space, sf::Keyboard::Space);
}

void KeyBoard::updateKey(Key& k, sf::Keyboard::Key sfk)
{
	if (!k.isHold && k.active)
		k.active = false;

	if (sf::Keyboard::isKeyPressed(sfk))
		k.down = true;
	else
	{
		k.down = false;
		k.used = false;
		k.active = false;
	}

	if (k.down && !(k.used))
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
	case 'S':	return shift.active;
	case ' ':	return space.active;
	}
}