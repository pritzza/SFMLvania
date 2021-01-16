#pragma once

#include "State.h"

#include "../levels/Level.h"
#include "../levels/LevelEditor.h"

#include "../player/Player.h"

#include <SFML/Graphics.hpp>

enum class TILE_SOLID;
enum class TILE_SPECIAL;

class EditorState : public State
{
private:
	Player p;

	Level l;
	LevelEditor editor;

	const std::string levelFileName;

	sf::Text t;

public:
	EditorState(GameData& data, const std::string& levelFileName);
	~EditorState() override;

	void virtual init();

	void virtual handleInput();	// makes events based on keyboard input
	void virtual update(const float dt, const int f);	// updates all objects of state
	void virtual render();
};