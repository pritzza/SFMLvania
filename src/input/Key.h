#pragma once

enum class KEY_TYPE
{
	TAP,	// only activates first frame of being pressed, only reset once released
	HOLD	// active every frame that it's down
};

struct Key
{
	bool down{};	// state of physical key
	bool active{};	// is the game considering the key pressed
	bool used{};	// only used if TAP_KEY type

	const KEY_TYPE type;

	Key(const KEY_TYPE type)
		:
		type{ type }
	{}
};