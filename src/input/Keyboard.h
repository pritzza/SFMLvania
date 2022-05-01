#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"

class KeyBoard
{
private:
	sf::RenderWindow& window;

public:
	Button w, a, s, d, e, shift, space, up, down, left, right;

public:
	KeyBoard(sf::RenderWindow& w)
		:
		window{ w }
	{}

	void update();	// calls every key's update() method
};