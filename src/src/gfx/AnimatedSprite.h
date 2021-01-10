#pragma once

#include "Sprite.h"

class AnimatedSprite : public Sprite
{
private:
	const unsigned int maxKeyFrames;	// how many unique frames there are
	unsigned int keyFramesCounter{};	// what unique frame we're on

	const unsigned int maxTweens;	// how many frames between key frame change
	unsigned int tweensCounter{}	// how close we are to incrementing keyFramesCounter

};