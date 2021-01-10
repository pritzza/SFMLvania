#pragma once

class Event	// all event should be dynamically constructed as an argument for the EventHandler's .addEvent() method
{
public:
	void virtual eventAction() = 0;	// all events are dynamically allocated and should be passed into the EventHandler, processed, then deleted all by the EventHandler
};