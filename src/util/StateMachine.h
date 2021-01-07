#pragma once

#include <unordered_map>

#include "../states/State.h"

enum class STATES
{
	VOID, // null state
	MAIN,
	MENU,
};

class StateMachine
{
private:
	std::unordered_map<STATES, State*> states;

	State* tempState;

	STATES currentStateID;

	bool isChanging{ false };
	bool isAdding{ false };
	bool isRemoving{ false };

	STATES changingState{ STATES::VOID };
	STATES addingState{ STATES::VOID };
	STATES removingState{ STATES::VOID };

	void processRemoving();
	void processChanging();
	void processAdding();

public:
	~StateMachine();

	void processStateChange();

	State* currentState();

	void changeState(const STATES s);
	void addState(const STATES s, State* ts);
	void removeState(const STATES s);
};