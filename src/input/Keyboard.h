#pragma once

#include <SFML/Graphics.hpp>

#include "Key.h"

class KeyBoard
{
private:
	sf::RenderWindow& window;

	Key w, a, s, d, shift, space;

public:
	KeyBoard(sf::RenderWindow& w, const unsigned int FPS)
		:
		window{ w },
		w { true },
		a{ true },
		s{ true },
		d{ true },
		shift{ false },
		space{ false }
	{}

	void update();
	void updateKey(Key& k, sf::Keyboard::Key sfk);

	const bool isActive(const char c) const;
};