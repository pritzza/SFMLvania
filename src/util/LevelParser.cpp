#include "LevelParser.h"

const unsigned int LevelParser::getIndex(const unsigned int s) const
{
	for (int i = 0; i < TileData::NUM_IDS; ++i)
		if (ids[i].in == s)
			return i;

	return 0;
}

const unsigned int LevelParser::getIndex(const TILE_SOLID s) const
{
	for (int i = 0; i < TileData::NUM_SOLIDS; ++i)
		if (solids[i].in == s)
			return i;

	return 0;
}

const unsigned int LevelParser::getIndex(const TILE_SPECIAL s) const
{
	for (int i = 0; i < TileData::NUM_SPECIALS; ++i)
		if (specials[i].in == s)
			return i;

	return 0;
}

const unsigned int LevelParser::getSpriteIndex(const char id) const
{
	for (int i = 0; i < TileData::NUM_IDS; ++i)
		if (ids[i].out == id)
			return i;

	return 0;
}

const unsigned int LevelParser::getSolidIndex(const char id) const
{
	for (int i = 0; i < TileData::NUM_SOLIDS; ++i)
		if (solids[i].out == id)
			return i;

	return 0;
}

const unsigned int LevelParser::getSpecialIndex(const char id) const
{
	for (int i = 0; i < TileData::NUM_SPECIALS; ++i)
		if (specials[i].out == id)
			return i;

	return 0;
}

const unsigned int LevelParser::parseSpriteID(const unsigned int id) const
{
	return ids[id].in;
}

const TILE_SOLID LevelParser::parseSolid(const unsigned int id) const
{
	return solids[id].in;
}

const TILE_SPECIAL LevelParser::parseSpecial(const unsigned int id) const
{
	return specials[id].in;
}

const char LevelParser::unparseSpriteID(const unsigned int id) const
{
	return ids[id].out;
}

const char LevelParser::unparseSolid(const unsigned int id) const
{
	return solids[id].out;
}

const char LevelParser::unparseSpecial(const unsigned int id) const
{
	return specials[id].out;
}