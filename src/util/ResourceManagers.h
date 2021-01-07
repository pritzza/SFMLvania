#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

struct ResourceManagers
{
	ResourceManager<TEXTURES, sf::Texture> textureManager;	// MAKE SURE THE RESOURCE ISNT A POINTER
	ResourceManager<FONTS, sf::Font> fontManager;
	//ResourceManager<SOUNDS, sf::Sound> soundManager;
};