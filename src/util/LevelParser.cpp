#include "LevelParser.h"

#include "../levels/TileData.h"

const unsigned int LevelParser::parseSpriteID(const char id) const
{
	unsigned int tile{ TILE_SPRITE_ID::MISSING_TILE };
	switch (id)
	{
	case ' ': tile = TILE_SPRITE_ID::AIR;		break;
	case '#': tile = TILE_SPRITE_ID::BRICK;		break;
	case 'o': tile = TILE_SPRITE_ID::GROUND;	break;
	case '-': tile = TILE_SPRITE_ID::PLATFORM;	break;
	case 'v': tile = TILE_SPRITE_ID::FACE;		break;
	case 'b': tile = TILE_SPRITE_ID::BARREL;	break;
	case '.': tile = TILE_SPRITE_ID::PEBBLE;	break;
	}

	return tile;
}

const TILE_SOLID LevelParser::parseSolid(const char id) const
{
	TILE_SOLID solid{ TILE_SOLID::SOLID };

	switch (id)
	{
	case ' ': solid = TILE_SOLID::NOT_SOLID;
	}

	return solid;
}

const TILE_SPECIAL LevelParser::parseSpecial(const char id) const
{
	TILE_SPECIAL special{ TILE_SPECIAL::NONE };

	switch (id)
	{
		//case '1': special = TILE_SPECIAL::SOMETHING;
	}

	return special;
}

const char LevelParser::unparseSpriteID(const unsigned int id) const
{
	char c{ ' ' };
	switch (id)
	{
	case TILE_SPRITE_ID::AIR:		c = ' ';	break;
	case TILE_SPRITE_ID::BRICK:		c = '#';	break;
	case TILE_SPRITE_ID::GROUND:	c = 'o';	break;
	case TILE_SPRITE_ID::PLATFORM:	c = '-';	break;
	case TILE_SPRITE_ID::FACE:		c = 'v';	break;
	case TILE_SPRITE_ID::BARREL:	c = 'b';	break;
	case TILE_SPRITE_ID::PEBBLE:	c = '.';	break;
	}

	return c;
}

const char LevelParser::unparseSolid(const TILE_SOLID solid) const
{
	char c{ ' ' };
	switch (solid)
	{
	case TILE_SOLID::SOLID: c = '.'; break;
	case TILE_SOLID::NOT_SOLID: c = ' '; break;
	}

	return c;
}

const char LevelParser::unparseSpecial(const TILE_SPECIAL special) const
{
	char c{ ' ' };
	switch (special)
	{
	case TILE_SPECIAL::NONE: c = ' '; break;
	}

	return c;
}