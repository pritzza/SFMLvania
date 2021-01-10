#pragma once

#include "Event.h"

enum class STATE_EVENT_TYPE
{
	CHANGE,	// queue stateMachine to change state to a different, existing state
	ADD,	// queue stateMachine to add a new state to its container of states. Pass in a dynamic pointer of the state you want to add, include what level you want to load if game/editor state
	REMOVE	// queue stateMachine to remove and deallocate a state from its container
};

enum class LEVEL
{
	VOID,	// NA or null
	TEST,	// not really a level, just a demo map that im using for now to mess around in
};

enum class STATES;

class GameData;

class StateEvent : public Event
{
private:
	GameData& data;

	const STATES stateID;
	const STATE_EVENT_TYPE eventType;
	const LEVEL lvl;	// lvl only used when specifiying the level of the state you're adding (some states like MENU wont have levels, so will be set to LEVE::VOID)

private:
	void stateEvent();

	void add();
	void change();
	void remove();

public:
	StateEvent(GameData& data, const STATES stateID, const STATE_EVENT_TYPE action, const LEVEL lvl)
		:
		data{ data },
		stateID{ stateID },
		eventType{action},
		lvl{lvl}
	{}

	StateEvent(GameData& data, const STATES stateID, const STATE_EVENT_TYPE action)
		:
		data{ data },
		stateID{ stateID },
		eventType{ action },
		lvl{ LEVEL::VOID }	// set level to void if not specefied
	{}

	void virtual eventAction();

};