#include "Player.h"

#include "../levels/TileMap.h"
#include "../levels/Tile.h"
#include "../levels/TileData.h"

#include "../util/Window.h"

#include <iostream>

void Player::update(const float dt, TileMap& t)
{
	updatePhysics(dt);
	updateTileCollisions(t);
	updatePos(t);

	s.update();

	//resetJump()
}

void Player::updatePhysics(const float dt)
{
	//yVel += FORCE_OF_GRAVITY;

	yVel *= dt + 1;
	xVel *= dt + 1;
}

void Player::checkHorizontalCollision(TileMap& t, const int collisionPoints, const int w, const int x, const int ts)
{
	//for (int i = 0; i < collisionPoints; ++i)	// iterate through points in bounding box, each point is the length of one tile apart
	//{
	//	// collision points in tiles turned into the index of the tile they're inside
	//	// the things being subtracted move the bottom and leftmost collision points top and right one pixel respectivly prevent collision points from bleeding outside boundries
	//	const int currentTile = x + (i % (w + 1) * ts) - ((i % (w + 1)) / w);
	//	int nextTile = (x + xVel) + (i % (w + 1) * ts) - ((i % (w + 1)) / w);
	//
	//	if (t.getTile(nextTile, currentTile).getSolid() == TILE_SOLID::SOLID)	// if horizontal collision
	//	{
	//		if (xVel > 0)		s.setPos((((s.getPos().x + ts - 1) / ts) * ts), s.getPos().y);
	//		else if (xVel < 0)	s.setPos((((s.getPos().x + 0  - 0) / ts) * ts), s.getPos().y);
	//		xVel = 0;
	//	}
	//}
}

void Player::updateTileCollisions(TileMap& t)
{
	const int ts = t.getTile(0).getSize() / t.getTile(0).getAABB().getScale();	// tile size in pixels
	const sf::Vector2i d(s.bb.getSize().x * s.bb.getScale(), s.bb.getSize().y * s.bb.getScale());	// dimensions
	const sf::Vector2i pos(s.bb.getPos().x, s.bb.getPos().y);

	const int collisionPoints = (d.x + 1) * (d.y + 1);

	for (int i = 0; i < collisionPoints; ++i)	// iterate through points in bounding box, each point is the length of one tile apart
	{
		const sf::Vector2i next(s.bb.getPos().x + xVel, s.bb.getPos().y + yVel);
	
		// collision points in tiles turned into the index of the tile they're inside
		// the things being subtracted move the bottom and leftmost collision points top and right one pixel respectivly prevent collision points from bleeding outside boundries
		const sf::Vector2i currentTile(	pos.x  + (i % (d.x + 1) * ts) - ((i % (d.x + 1)) / d.x), pos.y  + (i / (d.x + 1) * ts) - i / (((d.x + 1) * (d.y + 1)) - (d.x + 1)));
		sf::Vector2i nextTile(			next.x + (i % (d.x + 1) * ts) - ((i % (d.x + 1)) / d.x), next.y + (i / (d.x + 1) * ts) - i / (((d.x + 1) * (d.y + 1)) - (d.x + 1)));
		
		boundingBoxes[i].turnIntoPoint();
		boundingBoxes[i].setPos(nextTile.x, nextTile.y);

		if (t.getTile(nextTile.x, currentTile.y).getSolid() == TILE_SOLID::SOLID)	// if horizontal collision
		{
			if (xVel > 0)		s.setPos((((pos.x + ts - 1) / ts) * ts), pos.y);
			else if (xVel < 0)	s.setPos((((pos.x +  0 - 0) / ts) * ts), pos.y);
			xVel = 0;
		}
	}

	for (int i = 0; i < collisionPoints; ++i)	// iterate through points in bounding box, each point is the length of one tile apart
	{
		const sf::Vector2i next(s.bb.getPos().x + xVel, s.bb.getPos().y + yVel);

		// collision points in tiles turned into the index of the tile they're inside
		// the things being subtracted move the bottom and leftmost collision points top and right one pixel respectivly prevent collision points from bleeding outside boundries
		const sf::Vector2i currentTile(pos.x + (i % (d.x + 1) * ts) - ((i % (d.x + 1)) / d.x), pos.y + (i / (d.x + 1) * ts) - i / (((d.x + 1) * (d.y + 1)) - (d.x + 1)));
		sf::Vector2i nextTile(next.x + (i % (d.x + 1) * ts) - ((i % (d.x + 1)) / d.x), next.y + (i / (d.x + 1) * ts) - i / (((d.x + 1) * (d.y + 1)) - (d.x + 1)));
		if (t.getTile(nextTile.x, nextTile.y).getSolid() == TILE_SOLID::SOLID)	// if vertical collision
		{
			if (yVel > 0)		s.setPos(pos.x, (((pos.y + ts - 1) / ts) * ts));
			else if (yVel < 0)	s.setPos(pos.x, (((pos.y + 0 - 0) / ts) * ts));
			yVel = 0;
			//isGrounded = true;
		}

		if (i > ((d.x + 1) * (d.y + 1)) - (d.x + 2)) // platform collision	// only check collision point at the bottom of the bounding box (what you're standing on)
		{
			if (t.getTile(nextTile.x, nextTile.y).getSolid() == TILE_SOLID::PLATFORM && nextTile.y % ts < ts / 4)	// only if ur on the top 2 pixels
				if (yVel > 0)
				{
					s.setPos(pos.x, (((pos.y) / ts) * ts));
					yVel = 0;
					//isGrounded = true;
				}
		}
	}
}

void Player::updatePos(TileMap& t)
{
	s.setPos(s.getPos().x + xVel, s.getPos().y + yVel);

	if (!xVel && !yVel)
		s.setIdle(true);

	xVel = 0;
	yVel = 0;
}

void Player::move(const int x, const int y)
{
	++movementCounter;

	if (movementCounter % 1 == 0)
	{
		this->xVel += x * 1;
		this->yVel += y * 1;

		s.setIdle(false);
	}

	// change direction based on where ur moving
	if      (x == -1 && y ==  0)		this->s.setDirection(DIRECTION::LEFT);
	else if (x ==  1 && y ==  0)		this->s.setDirection(DIRECTION::RIGHT);
	//else if (x ==  0 && y == -1)		this->s.setDirection(DIRECTION::UP);
	//else if (x ==  0 && y ==  1)		this->s.setDirection(DIRECTION::DOWN);
}

void Player::jump()
{
}