#pragma once

class Event
{
public:
	void virtual eventAction() = 0;	// all events are dynamically allocated and should be passed into the EventHandler, processed, then deleted all by the EventHandler
};