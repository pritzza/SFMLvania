#pragma once

#include <SFML/Graphics.hpp>

#include "Key.h"

class KeyBoard
{
private:
	sf::RenderWindow& window;

public:
	Key w, a, s, d, e, shift, space;

public:
	KeyBoard(sf::RenderWindow& w)
		:
		window{ w }
	{}

	void update();	// calls every key's update() method
};