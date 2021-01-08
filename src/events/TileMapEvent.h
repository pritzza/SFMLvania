#pragma once

#include "Event.h"

class TileMap;

enum class TILE_SOLID;
enum class TILE_SPECIAL;

class TileMapEvent : public Event
{
private:
	TileMap& tm;
	const unsigned int tileIndex;

	const unsigned int spriteID;
	const TILE_SOLID solid;
	const TILE_SPECIAL special;

public:
	TileMapEvent(TileMap& tm, const unsigned int ti, const unsigned int si, const TILE_SOLID s, const TILE_SPECIAL sp)
		:
		tm{ tm },
		tileIndex{ ti },
		spriteID{ si },
		solid{ s },
		special{ sp }
	{}

	void virtual eventAction();

private:
	void insertTile();

};