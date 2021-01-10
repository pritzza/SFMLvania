#include "Sprite.h"

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
	initSprite(t);
	initRect();
}

void Sprite::init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y)
{
	this->spriteID = id;
	this->width = w;
	this->height = h;
	this->scale = s;
	this->xPos = x;
	this->yPos = y;

	initSprite(t);
	initRect();
}

void Sprite::initSprite(sf::Texture& t)
{
	this->sprite.setTexture(t);

	this->setUp();
}

void Sprite::initRect()
{
	this->boundingBox.setFillColor(sf::Color(255, 255, 255, 0));	// set fill on bounding box to be clear

	this->boundingBox.setOutlineThickness(1.f / 8 );	// creates nice thin outline around every sprites	
	this->boundingBox.setSize(sf::Vector2f((width * SPRITE_SIZE), (height * SPRITE_SIZE)));		// wrap outline around sprite dimensions
	this->updateBoundingBoxColor();		// gives color to outline
}

void Sprite::update()
{
	this->updatePos();
}

void Sprite::setUp()
{
	this->updatePos();
	this->updateScale();
	this->updateCrop();
	this->updateBoundingBoxColor();
}

void Sprite::updateBoundingBoxColor()
{
	this->boundingBox.setOutlineColor(this->boundingBoxColor);
}

void Sprite::updateScale()
{
	this->sprite.setScale(scale, scale);
	this->boundingBox.setScale(scale, scale);
}

void Sprite::updateCrop()
{
	// sprite x start in spritesheet, sprite y start in spritesheet, then x, and y end
	// use ID to select out image in spritesheet
	this->sprite.setTextureRect(sf::IntRect(0, height * spriteID * SPRITE_SIZE, width * SPRITE_SIZE, height * SPRITE_SIZE));
}

void Sprite::updatePos()
{
	this->sprite.setPosition(this->xPos, this->yPos);
	this->boundingBox.setPosition(this->xPos, this->yPos);
}

void Sprite::setBoundingBoxColor(const BORDER_COLOR c)
{
	switch (c)
	{
	case BORDER_COLOR::RED:		this->boundingBoxColor = sf::Color(200, 0,   0);	break;	// red
	case BORDER_COLOR::GREEN:	this->boundingBoxColor = sf::Color(0,   200,  0);	break;	// green
	default:					this->boundingBoxColor = sf::Color(222, 222, 222);	break;	// white
	}
}

void Sprite::setBoundingBoxOutlineThickness(const unsigned int t)
{
	this->boundingBox.setOutlineThickness(t / 10.f);
}

void Sprite::setPos(const int x, const int y)
{
	this->xPos = x;
	this->yPos = y;

	this->updatePos();
}

const sf::Vector2i Sprite::getPos() const
{
	return sf::Vector2i(this->xPos, this->yPos);
}

sf::Sprite& Sprite::getSprite()
{
	return this->sprite;
}

void Sprite::setID(const unsigned int id)
{
	this->spriteID = id;
}

const unsigned int Sprite::getID() const
{
	return this->spriteID;
}

void Sprite::setTexture(const sf::Texture& t)
{
	this->sprite.setTexture(t);
}

void Sprite::draw(Window& window, const bool drawRect)
{
	window.draw(this->sprite);

	if (drawRect)
		window.draw(this->boundingBox);
}

void Sprite::draw(Window& window)
{
	window.draw(this->sprite);
}