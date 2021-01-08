#include "TileMapEvent.h"

#include "../levels/TileMap.h"
#include "../levels/Tile.h"


void TileMapEvent::eventAction()
{
	this->insertTile();
}

void TileMapEvent::insertTile()
{
	this->tm.getTile(tileIndex).update(spriteID, solid, special);
}
