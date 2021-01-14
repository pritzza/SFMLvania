#pragma once

#include "../gfx/AnimatedSprite.h"

class TileMap;

class Player
{
private:
	int xVel{};
	int yVel{};

	const int FORCE_OF_GRAVITY{ 2 };
	unsigned int movementCounter{};

public:
	AnimatedSprite s;

	AABB* boundingBoxes = nullptr;

private:
	void updatePos(TileMap& t);
	void updatePhysics(const float dt);

	void updateTileCollisions(TileMap& t);

	void checkHorizontalCollision(TileMap& t, const int collisionPoints, const int w, const int x, const int ts);

public:
	void update(const float dt, TileMap& t);

	void jump();

	void move(const int x, const int y);
};