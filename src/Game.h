#pragma once

#include <SFML/Graphics.hpp>

#include "util/GameData.h"

class Game
{
private:
	GameData data;

	sf::Clock clock;
	const unsigned int FPS{ 60 };

private:
	bool isRunning() const;

public:
	Game(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size);

	void gameLoop();

};