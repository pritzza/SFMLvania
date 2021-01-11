#include "StateEvent.h"

#include "../util/GameData.h"

#include "../states/GameState.h"
#include "../states/MenuState.h"
#include "../states/EditorState.h"

void StateEvent::stateEvent()
{
	switch (eventType)
	{
	case STATE_EVENT_TYPE::ADD:
		add();	// the constructor for a state is called in add()
		break;
	case STATE_EVENT_TYPE::CHANGE:
		change();
		break;
	case STATE_EVENT_TYPE::REMOVE:
		remove();
		break;
	}
}

void StateEvent::add()
{
	std::string levelFileName{ "res/levels/test1.txt" };	// default case

	switch (lvl)	// parse enum class LEVEL into actual address of level data file
	{
	case LEVEL::TEST:
		levelFileName = "res/levels/test1.txt";
		break;
	}

	switch (stateID)
	{
	case STATES::GAME:
		this->data.stateMachine.addState(stateID, new GameState(data, levelFileName));
		break;
	case STATES::EDITOR:
		this->data.stateMachine.addState(stateID, new EditorState(data, levelFileName));
		break;
	case STATES::MENU:
		this->data.stateMachine.addState(stateID, new MenuState(data));	// MenuState doesnt have a need for levels, doesnt take it as arguments
		break;
	}
}

void StateEvent::change()
{
	this->data.stateMachine.changeState(stateID);
}

void StateEvent::remove()
{
	this->data.stateMachine.removeState(stateID);
}

void StateEvent::eventAction()
{
	this->stateEvent();
}
