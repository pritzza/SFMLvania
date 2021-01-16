#pragma once

#include "State.h"

class MenuState : public State
{
private:

public:
	MenuState(GameData& data);
	~MenuState() override;

	void virtual init();

	void virtual handleInput();	// makes events based on keyboard input
	void virtual update(const float dt, const int f);	// updates all objects of state
	void virtual render();
};