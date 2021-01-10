#include "Tile.h"

#include "../util/Window.h"
#include "../util/ResourceManager.h"

#include "../levels/TileData.h"

void Tile::init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->solid = solid;
	this->special = special;

	initSprite(tm, lvlw, pos, spriteID);
}

void Tile::initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int id)
{
	this->updateRectColor();	// get the color of the bounding box set depending on solid

	// position for tileSprite corresponding to its place in the tileMap, and data on tiles' and sprites' size
	const unsigned int x{ (pos % lvlw) * this->LENGTH * this->SCALE * this->sprite.SPRITE_SIZE };
	const unsigned int y{ (pos / lvlw) * this->LENGTH * this->SCALE * this->sprite.SPRITE_SIZE };

	this->sprite.init(*tm.load(TEXTURES::TILES), id, LENGTH, LENGTH, SCALE, x, y);
}

void Tile::setTile(const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->sprite.setID(spriteID);
	this->solid = solid;
	this->special = special;

	this->updateSprite();
}

void Tile::updateSprite()
{
	this->updateRectColor();
	this->sprite.setUp();
}

void Tile::updateRectColor()
{
	switch (solid)	// gives color to tiles' sprite's boundingBox depending on solid value
	{
	case TILE_SOLID::NOT_SOLID:	 this->sprite.setBoundingBoxColor(BORDER_COLOR::WHITE);		break;
	case TILE_SOLID::SOLID:		 this->sprite.setBoundingBoxColor(BORDER_COLOR::RED);	    break;
	}
}

void Tile::setPosition(const int x, const int y)
{
	this->sprite.setPos(
		x * LENGTH * SCALE * this->sprite.SPRITE_SIZE,
		y * LENGTH * SCALE * this->sprite.SPRITE_SIZE
	);
}

void Tile::setBoundingBoxOutlineThickness(const unsigned int t)
{
	this->sprite.setBoundingBoxOutlineThickness(t);
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

void Tile::draw(Window& window, const bool drawRect)
{
	this->sprite.draw(window, drawRect);
}

void Tile::draw(Window& window)
{
	this->sprite.draw(window);
}
