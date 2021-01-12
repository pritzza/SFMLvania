#include "Player.h"

#include "../levels/TileMap.h"
#include "../levels/Tile.h"
#include "../levels/TileData.h"

#include "../util/Window.h"

#include <vector>
#include <iostream>

void Player::update(const float dt, TileMap& t)
{
	updatePhysics(dt);
	updatePos(t);
}

void Player::updatePhysics(const float dt)
{
	yVel *= dt + 1;
	xVel *= dt + 1;
}

void Player::updatePos(TileMap& t)
{
	//s.bb.isColliding(t.getTile(0).getAABB());

	const unsigned int& ts{ t.getTile(0).getSize() };

	const unsigned int& w = s.bb.getSize().x * s.bb.getScale();
	const unsigned int& h = s.bb.getSize().y * s.bb.getScale();

	const unsigned int& cx = s.bb.getPos().x;	// current
	const unsigned int& cy = s.bb.getPos().y;

	for (int i = 0; i < (w + 1) * (h + 1); ++i)	// iterate through points in bounding box, each point is the length of one tile apart
	{
		const unsigned int& nx = s.bb.getPos().x + xVel;	// next pos
		const unsigned int& ny = s.bb.getPos().y + yVel;

		// collision points in tiles with next pos
		const int ntx = nx + ((i % (w + 1)) * ts);	// the tile index of the point we're checking collision for
		const int nty = ny + ((i / (w + 1)) * ts);

		// collision points in tiles with current pos
		const int ctx = cx + ((i % (w + 1)) * ts);	// the tile index of the point we're checking collision for
		const int cty = cy + ((i / (w + 1)) * ts);

		// if vertical collision
		if (t.getTile(ctx, nty).getSolid() == TILE_SOLID::SOLID)
			yVel = 0;
			//t.getTile(ctx, nty).setOutlineThickness(6);

		// if horizontal collision
		if (t.getTile(ntx, cty).getSolid() == TILE_SOLID::SOLID)
			xVel = 0;
			//t.getTile(ntx, cty).setOutlineThickness(6);

	}

	s.setPos(s.getPos().x + xVel, s.getPos().y + yVel);
	s.update();

	xVel = 0;
	yVel = 0;
}

void Player::move(const int x, const int y)
{
	this->xVel += x;
	this->yVel += y;
}
