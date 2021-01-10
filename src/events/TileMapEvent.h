#pragma once

#include "Event.h"

class TileMap;

enum class TILE_SOLID;
enum class TILE_SPECIAL;

class TileMapEvent : public Event	// used for inserting or modifying tileMap data of current level
{
private:
	TileMap& tm;
	const unsigned int targetTileIndex;	// index of tile in tileMap you are trying to modify

	// the data you are passing into the tile.update() method
	const unsigned int spriteID;
	const TILE_SOLID solid;
	const TILE_SPECIAL special;

private:
	void insertTile();	

public:
	TileMapEvent(TileMap& tm, const unsigned int tti, const unsigned int si, const TILE_SOLID s, const TILE_SPECIAL sp)
		:
		tm{ tm },
		targetTileIndex{ tti },
		spriteID{ si },
		solid{ s },
		special{ sp }
	{}

	void virtual eventAction();

};