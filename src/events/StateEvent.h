#pragma once

#include "Event.h"

enum class STATE_EVENT_TYPE
{
	CHANGE,
	ADD,
	REMOVE
};

enum class LEVEL
{
	VOID,	// NA or null
	TEST,
};

enum class STATES;

class State;
class GameData;

class StateEvent : public Event
{
private:
	GameData& data;

	const STATES stateID;
	const STATE_EVENT_TYPE eventType;
	const LEVEL lvl;

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