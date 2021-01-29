#include "AnimatedSprite.h"

#include <iostream>

AnimatedSprite::AnimatedSprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y, const int mkf, const int mtf)
{
	init(t, id, w, h, s, x, y, mkf, mtf);
}

void AnimatedSprite::init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y, const int mkf, const int mtf)
{
	this->maxKeyFrames = mkf;
	this->maxTweens = mtf;

	// taken from sprite
	this->spriteID = id;

	bb.init(w, h, x, y, s);

	initSprite(t);
}

void AnimatedSprite::update()
{
	updateAnimation();
	this->updatePos();
	this->bb.update();
}

void AnimatedSprite::updateDirection(const unsigned int d)
{
	this->direction = d % 4;
}

void AnimatedSprite::updateAnimation()
{
	if (isIdle)
	{
		keyFramesCounter = 0;
		updateCrop();
	}
	else
	{
		++tweensCounter;

		if (tweensCounter > maxTweens)
		{
			tweensCounter = 0;
			++keyFramesCounter;

			if (keyFramesCounter >= maxKeyFrames)
				keyFramesCounter = 0;	// !isIdle;// toggle idle from from animation

			updateCrop();
		}
	}
}

void AnimatedSprite::updateCrop()
{
	// sprite x start in spritesheet, sprite y start in spritesheet, then x, and y end
	// use ID to select out image in spritesheet
	const int width = (((bb.getSize().x - 1) / SPRITE_SIZE) * SPRITE_SIZE);
	const int height = (((bb.getSize().y - 1) / SPRITE_SIZE) * SPRITE_SIZE);

	const int directionalOffset = (width + 1) * (direction * maxKeyFrames);
	const int keyFrameIndex = (width + 1) * (keyFramesCounter - 0);	// - isIdle);	// toggles idle frame form animation
	const int idleOffset = 0;// width * isIdle;	// toggle idleframe form animation

	this->sprite.setTextureRect(
		sf::IntRect(
			keyFrameIndex + directionalOffset + idleOffset,
			height * spriteID,
			width,
			height)
	);
}
void AnimatedSprite::setIdle(const bool i)
{
	this->isIdle = i;
}

void AnimatedSprite::setDirection(const unsigned int d)
{
	this->direction = d;
	updateCrop();
}