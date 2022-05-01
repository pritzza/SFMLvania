#pragma once

#include "Sprite.h"

enum DIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class AnimatedSprite : public Sprite
{
private:
	unsigned int direction{};

	bool isIdle{};

	unsigned int maxKeyFrames{ 1 };	// how many unique frames there are
	unsigned int keyFramesCounter{};	// what unique frame we're on

	unsigned int maxTweens{ 1 };	// how many frames between key frame change
	unsigned int tweensCounter{};	// how close we are to incrementing keyFramesCounter

private:
	
	void updateCrop() override;

public:
	AnimatedSprite() {};
	AnimatedSprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y, const int mkf, const int mtf);
	void init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y, const int mkf, const int mtf);
	
	void update() override;

	void updateAnimation();	// ticks tweenCounter 1 and processes
	void updateDirection(const unsigned int d);
	
	void setIdle(const bool i);
	void setDirection(const unsigned int d);
};