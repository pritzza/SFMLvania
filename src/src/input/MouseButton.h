#pragma once

class MouseButton	// wrapper for mouse buttons
{
public:
	bool held{};

	unsigned int heldDuration{};	// how long has been held
	const unsigned int heldThreshold{};	// how many frames until considered held

	bool clicked{};

public:
	MouseButton(const unsigned int h)
		:
		heldThreshold{ h }
	{}

};