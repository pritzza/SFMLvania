#include "StateMachine.h"

#include <iostream>

#include "../events/StateEvent.h"

StateMachine::~StateMachine()
{
	for (auto it = states.begin(); it != states.end(); ++it)
		delete states.at(it->first);
}

void StateMachine::processRemoving()
{
	if (isRemoving)
	{
		if (states.find(removingState) != states.end())	// if removingState is loaded
		{
			delete states.at(removingState);
			states.erase(removingState);
		}

		isRemoving = false;
		removingState = STATES::VOID;
	}
}

void StateMachine::processAdding()
{
	if (isAdding)
	{
		if (addingState != STATES::VOID)	// if addingState is valid state
			if (states.find(addingState) == states.end())	// if addingState isn't already loaded
				states.insert({ addingState, tempState });

		isAdding = false;
		addingState = STATES::VOID;
		tempState = nullptr;
	}
}

void StateMachine::processChanging()
{
	if (isChanging)
	{
		if (states.find(changingState) != states.end()) // if changingState is loaded
			currentStateID = changingState;

		isChanging = false;
		changingState = STATES::VOID;
	}
}

void StateMachine::processStateChange()
{
	processRemoving();
	processAdding();	// the constructor for a state is called as soon as you call stateEvent.add()
	processChanging();
}

State* StateMachine::currentState()
{
	if (states.at(currentStateID) != nullptr)
		return states.at(currentStateID);

	return nullptr;
}

void StateMachine::changeState(const STATES s)
{
	isChanging = true;
	changingState = s;
}

void StateMachine::addState(const STATES s, State* ts)
{
	isAdding = true;
	tempState = ts;
	addingState = s;
}

void StateMachine::removeState(const STATES s)
{
	isRemoving = true;
	removingState = s;
}