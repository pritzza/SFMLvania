#pragma once

#include <SFML/Graphics.hpp>

#include "MouseButton.h"

enum class MOUSE
{
	LEFT,
	RIGHT
};

class Window;

class Mouse
{
private:
	sf::Mouse mouse;

	sf::RenderWindow& w;

	MouseButton l;
	MouseButton r;

	int xPos{};
	int yPos{};

	const unsigned int dragThreshold{ 3 };		// if the mouse is pressed and moves more than 5 pixels, held is automatically enabled
	unsigned int dragDistance{};

private:
	void updateDrag();

	void updateCounter();
	void updateClicked();
	void updateHeld();

public:
	Mouse(sf::RenderWindow& w, const unsigned int FPS)
		:
		w{ w },
		l{ FPS / 4 },	// 4 is a magic number, it just feels right
		r{ FPS / 4 }
	{}

	void update();

	const bool isClicked(const MOUSE button) const;
	const bool isHeld(const MOUSE button) const;

	const sf::Vector2i getPos() const;

};