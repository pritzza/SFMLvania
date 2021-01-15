#pragma once

enum class KEY_STATE
{
	TAPPED,
	HELD,
	RELEASED,
	SLEEP
};

class Key
{
private:
	KEY_STATE state{ KEY_STATE::SLEEP };

private:
	void update(const bool down);

public:
	const bool isTapped() const;
	const bool isHeld() const;
	const bool isReleased() const;
	const bool isSleep() const;

	friend class KeyBoard;	// lets Keyboard access key.update()
};