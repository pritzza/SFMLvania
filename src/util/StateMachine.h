#pragma once

#include <unordered_map>
#include <memory>

#include "../states/State.h"

enum class STATES;

class StateMachine
{
private:
	std::unordered_map<STATES, std::shared_ptr<State>> states;

	std::shared_ptr<State> tempState;

	STATES currentStateID;

	bool isChanging{ false };
	bool isAdding{ false };
	bool isRemoving{ false };

	STATES changingState{ STATES::VOID };
	STATES addingState{ STATES::VOID };
	STATES removingState{ STATES::VOID };

private:
	void processRemoving();
	void processChanging();
	void processAdding();

public:
	void processStateChange();

	std::shared_ptr<State> currentState();

private:
	void changeState(const STATES s);
	void addState(const STATES s, std::shared_ptr<State> ts);
	void removeState(const STATES s);

	friend class StateEvent;	// you have to do these through my StateEvent wrapper
};