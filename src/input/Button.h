#pragma once

enum class BUTTON_STATE
{
	TAPPED,
	HELD,
	RELEASED,
	SLEEP
};

class Button
{
private:
	BUTTON_STATE state{ BUTTON_STATE::SLEEP };

private:
	void update(const bool down);

public:
	const bool isTapped() const;
	const bool isHeld() const;
	const bool isReleased() const;
	const bool isSleep() const;

	friend class KeyBoard;	// lets Buttonboard access key.update()
	friend class Mouse;
};