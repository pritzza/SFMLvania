#include "AABB.h"

#include "../gfx/Sprite.h"

#include "../util/Window.h"

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

const bool AABB::isColliding(const AABB& b) const
{
	const int b1x = b.getPos().x;
	const int b1y = b.getPos().y;

	const int w = b.getSize().x * b.getScale();
	const int h = b.getSize().y * b.getScale();

	const int b2x = b.getPos().x + w;
	const int b2y = b.getPos().y + h;

	if (this->xPos )
	return false;
}

void AABB::updateSize()
{
	this->rect.setSize(sf::Vector2f(width * scale, height * scale));	// wrap outline around 's dimensions
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

	updateColor();
}

void AABB::setOutlineThickness(const unsigned int t)
{
	this->rect.setOutlineThickness(t / static_cast<float>(Window::PIXEL_SIZE));
}

void AABB::turnIntoPoint()
{
	this->rect.setSize(sf::Vector2f(1,1));	// wrap outline around 's dimensions
	this->rect.setOutlineThickness(2 / static_cast<float>(Window::PIXEL_SIZE));
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
