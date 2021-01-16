#include "TileData.h"

#include "../util/LevelParser.h"

void TileData::iterateSprite(unsigned int& id)
{
	++id;
	id %= NUM_IDS;
}

void TileData::iterateSolid(TILE_SOLID& solid)
{
	LevelParser p;
	solid = p.parseSolid((p.getIndex(solid) + 1) % NUM_SOLIDS);
}

void TileData::iterateSpecial(TILE_SPECIAL& special)
{
	LevelParser p;
	special= p.parseSpecial((p.getIndex(special) + 1) % NUM_SPECIALS);
}

void TileData::iterateProperty(TILE_PROPERTY& property)
{
	switch (property)
	{
	case TILE_PROPERTY::SPRITE:		property = TILE_PROPERTY::SOLID; break;
	case TILE_PROPERTY::SOLID:		property = TILE_PROPERTY::SPECIAL; break;
	case TILE_PROPERTY::SPECIAL:	property = TILE_PROPERTY::SPRITE; break;
	}
}
