#include "AABB.h"

#include "../gfx/Sprite.h"

AABB::AABB(const unsigned int w, const unsigned int h, const int x, const int y, const unsigned int s)
{
	init(w, h, x, y, s); 
}

void AABB::init(const unsigned int w, const unsigned int h, const int x, const int y, const unsigned int s)
{
	this->setSize(w, h);
	this->setPos(x, y);
	this->setScale(s);

	setUp();
}

void AABB::setUp()
{
	this->rect.setFillColor(sf::Color(255, 255, 255, 0));	// make fill color clear

	this->setOutlineThickness(1);

	this->updateColor();		// gives color to outline
	this->updateSize();

	this->update();
}

void AABB::update()
{
	updatePos();
}

void AABB::updateSize()
{
	this->rect.setSize(sf::Vector2f(width * scale * Sprite::SPRITE_SIZE, height * scale * Sprite::SPRITE_SIZE));	// wrap outline around 's dimensions
}

void AABB::updatePos()
{
	this->rect.setPosition(this->getPos());
}

void AABB::updateColor()
{
	this->rect.setOutlineColor(this->color);
}

void AABB::setColor(const BORDER_COLOR c)
{
	switch (c)
	{
	case BORDER_COLOR::RED:		this->color = sf::Color(200, 0, 0);	break;	// red
	case BORDER_COLOR::GREEN:	this->color = sf::Color(0, 200, 0);	break;	// green
	default:					this->color = sf::Color(222, 222, 222);	break;	// white
	}
}

void AABB::setOutlineThickness(const unsigned int t)
{
	this->rect.setOutlineThickness(t / 8.f);
}

const sf::RectangleShape& AABB::getRect() const
{
	return this->rect;
}

void AABB::setScale(const unsigned int s)
{
	this->scale = s;
}

const unsigned int AABB::getScale() const
{
	return this->scale;
}

void AABB::setSize(const unsigned int w, const unsigned int h)
{
	this->width = w;
	this->height = h;
}

const sf::Vector2f AABB::getSize() const
{
	return sf::Vector2f(width, height);
}

void AABB::setPos(const unsigned int x, const unsigned int y)
{
	this->xPos = x;
	this->yPos = y;

	this->updatePos();
}

const sf::Vector2f AABB::getPos() const
{
	return sf::Vector2f(xPos, yPos);
}
