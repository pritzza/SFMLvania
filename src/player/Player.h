#pragma once

#include "../gfx/AnimatedSprite.h"

class TileMap;

class Player
{
private:
	int xVel{};
	int yVel{};

	unsigned int movementCounter{};
	unsigned int movementRate{ 1 };
	const int speed{ 1 };

	const int FORCE_OF_GRAVITY{ 2 }; const int MAX_X_VEL{ 1 };
	const int MAX_Y_VEL{ 2 };

	bool isGrounded{};
	bool isJumping{};

	const unsigned int jumpForce{ 50 };	// the smaller the number, the larger the force

	const unsigned int jumpDuration{ 50 };
	unsigned int jumpCounter{};

public:
	AnimatedSprite s;

	AABB* boundingBoxes = nullptr;

private:
	void updatePos(TileMap& t);
	void updatePhysics(const float dt);

	void updateTileCollisions(TileMap& t);

	void checkHorizontalCollision(TileMap& t, const int collisionPoints, const int w, const int x, const int ts);

	void resetJump();

public:
	void update(const float dt, TileMap& t);

	void jump();

	void move(const int x, const int y, const bool directionTapped);

	const sf::Vector2i getVel() const;
};