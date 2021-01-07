#include "Tile.h"

#include "../util/Window.h"
#include "../util/ResourceManager.h"

void Tile::init(ResourceManager<TEXTURES, sf::Texture>& tm, const int levelWidth, const int levelHeight, const int pos, const char type, const bool solid, const char special)
{
	this->type = type;
	this->isSolid = solid;
	this->special = special;

	this->s.setTexture(*tm.load(TEXTURES::DEFAULT));

	this->s.setScale(.1f, .1f);
	this->s.setPosition((pos % levelWidth) * width, (pos / levelWidth) * height);

	this->rect.setPosition((pos % levelWidth) * width, (pos / levelWidth) * height);
	this->rect.setSize(sf::Vector2f(width, height));
	this->rect.setFillColor(sf::Color(type, type, type));
	this->rect.setOutlineColor(sf::Color::White);
	this->rect.setOutlineThickness(1);
}

void Tile::draw(Window& window)
{
	if (type == ' ')
		window.draw(this->s);
	else
		window.draw(this->rect);
}
