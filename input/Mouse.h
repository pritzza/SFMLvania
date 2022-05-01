#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"

class Window;

class Mouse
{
private:
	sf::Mouse mouse;
	sf::RenderWindow& w;

public:
	Button left, middle, right;

public:
	Mouse(sf::RenderWindow& w, const unsigned int FPS)
		:
		w{ w }
	{}

	void update();
	const sf::Vector2i getPos() const;
};