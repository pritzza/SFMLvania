#pragma once

#include "../gfx/Sprite.h"

class TileMap;

class Player
{
private:
	int xVel{};
	int yVel{};

	const int FORCE_OF_GRAVITY{ 2 };
	unsigned int movementCounter{};

public:
	Sprite s;

private:
	void updatePos(TileMap& t);
	void updatePhysics(const float dt);

	void updateTileCollisions(TileMap& t);

public:
	void update(const float dt, TileMap& t);

	void jump();

	void move(const int x, const int y);
};