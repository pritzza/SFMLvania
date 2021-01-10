#pragma once

#include <SFML/Graphics.hpp>

#include "Key.h"

class KeyBoard
{
private:
	sf::RenderWindow& window;

	Key w, a, s, d, shift, space;

private:
	void updateKey(Key& k, sf::Keyboard::Key sfk);	// updates state of keys

public:
	KeyBoard(sf::RenderWindow& w, const unsigned int FPS)
		:
		window{ w },
		w{ KEY_TYPE::HOLD },
		a{ KEY_TYPE::HOLD },
		s{ KEY_TYPE::HOLD },
		d{ KEY_TYPE::HOLD },
		shift{ KEY_TYPE::TAP },
		space{ KEY_TYPE::TAP }
	{}

	void update();	// calls updateKey on every key

	const bool isActive(const char c) const;
};