#pragma once

#include "State.h"

#include "../levels/Level.h"
#include "../levels/Tile.h"

#include <SFML/Graphics.hpp>

enum class TILE_SOLID;
enum class TILE_SPECIAL;

class EditorState : public State
{
private:
	Level l;

	const std::string levelFileName;

	unsigned int ttProperty;

	Tile tempTile;
	unsigned int ttSpriteID;
	TILE_SOLID ttSolid;
	TILE_SPECIAL ttSpecial;

	sf::Text t;

public:
	EditorState(GameData& data, const std::string& levelFileName);
	~EditorState() override;

	void virtual handleInput();	// makes events based on keyboard input
	void virtual update(const float dt, const int f);	// updates all objects of state
	void virtual render();
};