#pragma once

#include "../gfx/AnimatedSprite.h"

class TileMap;

class Player
{
private:
	float xVel{};
	float yVel{};

	float xAcc{};
	float yAcc{};

	float speed{ .1f };

	const float FORCE_OF_GRAVITY{ .21f };

	const float MIN_X{ .1f };
	const float MAX_X_VEL{ 1.f };
	const float MAX_Y_VEL{ 6.9f };

	bool isGrounded{};
	bool isJumping{};

	float jumpCounter{};
	const int JUMP_FORCE{ 130 };
	const float JUMP_LIMIT{ .1f };

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
	~Player();

	void init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y, const int mkf, const int mtf);

	void update(const float dt, TileMap& t);

	void jump();
	void stopJump();

	void move(const int x, const int y, const bool directionTapped);

	const sf::Vector2f getVel() const;
	const sf::Vector2f getAcc() const;
};