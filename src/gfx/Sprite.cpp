#include "Sprite.h"

#include <SFML/Graphics.hpp>

#include "../util/Window.h"

Sprite::Sprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y)
	:
	spriteID{ id }, 
	width{ w }, 
	height{ h }, 
	scale{ s },
	xPos{ x }, 
	yPos{ y }
{
	this->sprite.setTexture(t);
	this->updateProperties();
}

void Sprite::init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y)
{
	this->spriteID = id;
	this->width = w;
	this->height = h;
	this->scale = s;
	this->xPos = x;
	this->yPos = y;

	this->sprite.setTexture(t);
	this->updateProperties();
}

void Sprite::draw(Window& window)
{
	window.draw(this->sprite);
}

void Sprite::update()
{
	this->updatePos();
}

void Sprite::updateProperties()
{
	this->update();

	this->updateScale();
	this->updateCrop();
}

void Sprite::updateScale()
{
	this->sprite.setScale(scale, scale);
}

void Sprite::updateCrop()
{
	this->sprite.setTextureRect(sf::IntRect(0, height * spriteID * SPRITE_SIZE, width * SPRITE_SIZE, height * SPRITE_SIZE));
}

sf::Sprite& Sprite::getSprite()
{
	return this->sprite;
}

const unsigned int Sprite::getID() const
{
	return this->spriteID;
}

void Sprite::updatePos()
{
	this->sprite.setPosition(this->xPos, this->yPos);
}

void Sprite::setPos(const int x, const int y)
{
	this->xPos = x;
	this->yPos = y;
}

const sf::Vector2i Sprite::getPos() const
{
	return sf::Vector2i(this->xPos, this->yPos);
}

void Sprite::setTexture(const sf::Texture& t)
{
	this->sprite.setTexture(t);
}

void Sprite::setID(const unsigned int id)
{
	this->spriteID = id;
}
