#pragma once

#include <memory>
#include <vector>

class Event;

class EventHandler
{
private:
	std::vector<std::shared_ptr<Event>> events;

	int added{};
	int removed{};

public:
	void processEvents();
	void addEvent(std::shared_ptr<Event> e);

private:
	void removeEvent();	// removes back element
	void removeAll();

};