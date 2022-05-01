#include "EventHandler.h"

#include "../events/Event.h"

void EventHandler::processEvents()
{
	for (auto& e : events)
		e->eventAction();

	removeAll();
}

void EventHandler::addEvent(std::shared_ptr<Event> e)
{
	events.push_back(e);
}

void EventHandler::removeEvent()
{
	events.pop_back();
}

void EventHandler::removeAll()
{
	while (events.empty() == false)
		removeEvent();
}