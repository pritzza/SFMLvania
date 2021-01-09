#include "Tile.h"

#include "../util/Window.h"
#include "../util/ResourceManager.h"

#include "../levels/TileData.h"

void Tile::init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->solid = solid;
	this->special = special;

	initSprite(tm, spriteID, lvlw, pos);

	const unsigned int rectStroke{ 1 };
	const unsigned int rectOpacity = 255 * (3.f / 4.f);

	initRect(rectStroke, rectOpacity);
}

void Tile::setPosition(const int x, const int y)
{
	this->sprite.setPos(
		x * LENGTH * SCALE * this->sprite.SPRITE_SIZE, 
		y * LENGTH * SCALE * this->sprite.SPRITE_SIZE
	);

	this->sprite.update();
}

void Tile::initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const unsigned int id, const int lvlw, const int pos)
{
	const unsigned int x{ (pos % lvlw) * LENGTH * SCALE * this->sprite.SPRITE_SIZE };
	const unsigned int y{ (pos / lvlw) * LENGTH * SCALE * this->sprite.SPRITE_SIZE };

	this->sprite.init(*tm.load(TEXTURES::TILES), id, LENGTH, LENGTH, SCALE, x, y);
}

void Tile::initRect(const unsigned int stroke, const unsigned int opacity)
{
	this->sprite.initRect(stroke, opacity);
	this->updateRect();
}

void Tile::update(const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->sprite.setID(spriteID);
	this->solid = solid;
	this->special = special;

	this->updateSprite();
	this->updateRect();
}

void Tile::updateSprite()
{
	this->sprite.updateProperties();
}

void Tile::updateRect()
{
	switch (solid)
	{
	case TILE_SOLID::NOT_SOLID:
		this->sprite.updateBoundingBoxColor(BORDER_COLOR::WHITE);
		break;
	case TILE_SOLID::SOLID:
		this->sprite.updateBoundingBoxColor(BORDER_COLOR::RED);
		break;
	}
}

const unsigned int Tile::getLength() const
{
	return this->LENGTH;
}

const unsigned int Tile::getSpriteID() const
{
	return this->sprite.getID();
}

const TILE_SOLID Tile::getSolid() const
{
	return this->solid;
}

const TILE_SPECIAL Tile::getSpecial() const
{
	return this->special;
}

const unsigned int Tile::getScale() const
{
	return this->SCALE;
}

void Tile::draw(Window& window, const bool drawRect)
{
	this->sprite.draw(window, drawRect);
}

void Tile::draw(Window& window)
{
	this->sprite.draw(window);
}
