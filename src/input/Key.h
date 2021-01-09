#pragma once

struct Key
{
	bool down{};
	bool active{};
	bool used{};
	const bool isHold{};

	Key(const bool hold)
		:
		isHold{ hold }
	{}
};