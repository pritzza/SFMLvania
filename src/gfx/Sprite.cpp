#include "Sprite.h"

#include "../util/Window.h"

Sprite::Sprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y)
{
	init(t, id, w, h, s, x, y);
}

void Sprite::init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int s, const int x, const int y)
{
	this->spriteID = id;

	bb.init(w, h, x, y, s);

	initSprite(t);
}

void Sprite::initSprite(sf::Texture& t)
{
	this->sprite.setTexture(t);

	this->setUp();
}

void Sprite::setUp()
{
	this->bb.setUp();

	this->updatePos();
	this->updateScale();
	this->updateCrop();
}

void Sprite::update()
{
	this->updatePos();
	this->bb.update();
}

void Sprite::updateScale()
{
	const int s = bb.getScale();

	this->sprite.setScale(s, s);
}

void Sprite::updateCrop()
{
	// sprite x start in spritesheet, sprite y start in spritesheet, then x, and y end
	// use ID to select out image in spritesheet
	const int width = bb.getSize().x;
	const int height = bb.getSize().y;

	this->sprite.setTextureRect(sf::IntRect(0, width * spriteID * SPRITE_SIZE, width * SPRITE_SIZE, height * SPRITE_SIZE));
}

void Sprite::updatePos()
{
	this->sprite.setPosition(bb.getPos());
}

void Sprite::setPos(const int x, const int y)
{
	this->bb.setPos(x, y);

	this->updatePos();
}

const unsigned int Sprite::getPixelWidth() const
{
	return this->bb.getSize().x * bb.getScale() * Sprite::SPRITE_SIZE;
}

const unsigned int Sprite::getPixelHeight() const
{
	return this->bb.getSize().y * bb.getScale() * Sprite::SPRITE_SIZE;
}

const sf::Vector2f Sprite::getPos() const
{
	return this->bb.getPos();
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
		window.draw(this->bb.getRect());
}

void Sprite::draw(Window& window)
{
	window.draw(this->sprite);
}