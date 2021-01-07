#pragma once

#include <SFML/Graphics.hpp>

class Window;

template <class Key, class Resource>
class ResourceManager;

enum class TEXTURES;

class Tile
{
private:
	sf::Sprite s;
	sf::RectangleShape rect;
	const unsigned int width{ 8 };
	const unsigned int height{ 8 };

	char type;
	bool isSolid;
	char special;

public:
	void init(ResourceManager<TEXTURES, sf::Texture>& tm, const int w, const int h, const int pos, const char type, const bool solid, const char special);

	void draw(Window& window);
};