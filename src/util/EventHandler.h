#pragma once

#include <vector>

class Event;

class EventHandler
{
private:
	std::vector<Event*> events;

	int added{};
	int removed{};

public:
	~EventHandler();

	void processEvents();
	void addEvent(Event* e);

private:
	void removeEvent();	// removes back element
	void removeAll();

};