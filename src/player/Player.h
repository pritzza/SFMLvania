#pragma once

#include "../gfx/Sprite.h"

class TileMap;

class Player
{
private:
	int xVel{};
	int yVel{};

public:
	Sprite s;

private:
	void updatePos(TileMap& t);
	void updatePhysics(const float dt);

public:
	void update(const float dt, TileMap& t);

	void move(const int x, const int y);
};