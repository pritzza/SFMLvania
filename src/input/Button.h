#pragma once

enum class KEY_TYPE
{
	PRESS,
	HOLD,
	BOTH
};

struct Button
{
private:
	const KEY_TYPE type;

public:
	bool held{};

	unsigned int heldDuration{};	// how long has been held
	const unsigned int heldThreshold{};	// how many frames until considered held

	bool clicked{};

public:
	Button(const unsigned int h, const KEY_TYPE t)
		:
		heldThreshold{ h },
		type{ t }
	{}

};