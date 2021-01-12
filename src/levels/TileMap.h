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

	void save(const std::string& fileName);

	Tile& getTile(const unsigned int index);
	Tile& getTile(const int x, const int y);	// returns tile at exact pixel


	const unsigned int getWidth() const;
	const unsigned int getHeight() const;

	void draw(Window& window, const bool drawRect);
	void draw(Window& window);
};