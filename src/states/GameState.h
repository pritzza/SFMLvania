#pragma once

#include "State.h"

#include "../levels/Level.h"

#include <SFML/Graphics.hpp>

class GameState : public State
{
private:
	Level l;

	sf::Sprite s;
	int w{ 19 };
	int h{ 13 };
	int cycle{ 0 };

	sf::Text t;

public:
	GameState(GameData& data);
	~GameState() override;

	void virtual handleInput();	// makes events based on keyboard input
	void virtual update(const float dt, const int f);	// updates all objects of state
	void virtual render();
};