#include "Tile.h"

#include "../util/Window.h"
#include "../util/ResourceManager.h"

void Tile::init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->solid = solid;
	this->special = special;

	initSprite(tm, spriteID, lvlw, pos);
	//initRect(lvlw, pos);
}

void Tile::initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const unsigned int id, const int lvlw, const int pos)
{
	const unsigned int x{ (pos % lvlw) * LENGTH * SCALE * this->sprite.SPRITE_SIZE };
	const unsigned int y{ (pos / lvlw) * LENGTH * SCALE * this->sprite.SPRITE_SIZE };

	this->sprite.init(*tm.load(TEXTURES::TILES), id, LENGTH, LENGTH, SCALE, x, y);
}

void Tile::initRect(const int lvlw, const int pos)
{
	//this->rect.setPosition((pos % lvlw) * length * scale, (pos / lvlw) * length * scale);
	//this->rect.setSize(sf::Vector2f(length, length));
	//this->rect.setFillColor(sf::Color(type, type, type));
}

void Tile::update(const unsigned int spriteID, const TILE_SOLID solid, const TILE_SPECIAL special)
{
	this->sprite.setID(spriteID);
	this->solid = solid;
	this->special = special;

	this->updateSprite();
}

void Tile::updateSprite()
{
	this->sprite.updateProperties();
}

const unsigned int Tile::parseSpriteID(const char id) const
{
	unsigned int tile{ TILE_SPRITE_ID::MISSING_TILE };
	switch (id)
	{
	case ' ': tile = TILE_SPRITE_ID::AIR;		break;
	case '#': tile = TILE_SPRITE_ID::BRICK;		break;
	case 'o': tile = TILE_SPRITE_ID::GROUND;	break;
	case '-': tile = TILE_SPRITE_ID::PLATFORM;	break;
	}

	return tile;
}

const TILE_SOLID Tile::parseSolid(const char id) const
{
	TILE_SOLID solid{ TILE_SOLID::SOLID };

	switch (id)
	{
	case ' ': solid = TILE_SOLID::NOT_SOLID;
	}

	return solid;
}

const TILE_SPECIAL Tile::parseSpecial(const char id) const
{
	TILE_SPECIAL special{ TILE_SPECIAL::NONE };

	switch (id)
	{
	//case '1': special = TILE_SPECIAL::SOMETHING;
	}

	return special;
}

const char Tile::unparseSpriteID() const
{
	char c{ ' ' };
	switch (this->sprite.getID())
	{
	case TILE_SPRITE_ID::AIR: c = ' '; break;
	case TILE_SPRITE_ID::BRICK: c = '#'; break;
	case TILE_SPRITE_ID::GROUND: c = 'o'; break;
	case TILE_SPRITE_ID::PLATFORM: c = '-'; break;
	}

	return c;
}

const char Tile::unparseSolid() const
{
	char c{ ' ' };
	switch (this->solid)
	{
	case TILE_SOLID::SOLID: c = '.'; break;
	case TILE_SOLID::NOT_SOLID: c = ' '; break;
	}

	return c;
}

const char Tile::unparseSpecial() const
{
	char c{ ' ' };
	switch (this->special)
	{
	case TILE_SPECIAL::NONE: c = ' '; break;
	}

	return c;
}

const unsigned int Tile::getLength() const
{
	return this->LENGTH;
}

const unsigned int Tile::getScale() const
{
	return this->SCALE;
}

void Tile::draw(Window& window)
{
	this->sprite.draw(window);
}
