#pragma once

#include "State.h"

#include "../levels/Level.h"

#include "../entities/Player.h"

#include <SFML/Graphics.hpp>

class GameState : public State
{
private:
	Player p;

	Level l;

	const std::string levelFileName;

public:
	GameState(GameData& data, const std::string& levelFileName);
	virtual ~GameState() override;

	void virtual init();

	void virtual handleInput();	// makes events based on keyboard input
	void virtual update(const float dt, const int f);	// updates all objects of state
	void virtual render();
};