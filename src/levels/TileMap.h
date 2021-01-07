#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Tile;
class Window;

template <class Key, class Resource>
class ResourceManager;

enum class TEXTURES;

class TileMap
{
private:
	unsigned int width;
	unsigned int height;
	Tile* tiles;

public:
	~TileMap();

	void load(const std::string& fileName, ResourceManager<TEXTURES, sf::Texture>& tm);

	void draw(Window& window);
};