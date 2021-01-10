#include "EventHandler.h"

#include "../events/Event.h"

EventHandler::~EventHandler()
{
	this->removeAll();
}

void EventHandler::processEvents()
{
	for (auto& e : events)
		e->eventAction();

	removeAll();
}

void EventHandler::addEvent(Event* e)
{
	events.push_back(e);
}

void EventHandler::removeEvent()
{
	delete events.back();
	events.pop_back();
}

void EventHandler::removeAll()
{
	while (events.empty() == false)
		removeEvent();
}