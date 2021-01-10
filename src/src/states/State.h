#pragma once

#include <iostream>

enum class STATES
{
	VOID, // null state
	GAME,
	EDITOR,
	MENU,	
};

class GameData;

class State
{
public:
	GameData& data;

public:
	State(GameData& data)
		:
		data{ data }
	{}
	virtual ~State() {}

	void virtual handleInput() = 0;	// makes events based on keyboard input
	void virtual update(const float dt, const int f) = 0;	// updates all objects of state
	void virtual render() = 0;
};