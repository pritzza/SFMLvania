#include "TileMap.h"

#include "Tile.h"

#include "../util/Window.h"

#include <fstream>
#include <string>

TileMap::~TileMap()
{
	delete[] tiles;
}

void TileMap::load(const std::string& fileName, ResourceManager<TEXTURES, sf::Texture>& tm)
{
	std::ifstream file(fileName);
	if (file)
	{
		std::string line;

		std::getline(file, line);
		this->width = std::stoi(line);
		std::getline(file, line);
		this->height = std::stoi(line);
		this->tiles = new Tile[width * height];

		for (int i = 0; i < height; ++i)
		{
			std::getline(file, line);   // iterate through all of the file's lines from top to bottom
			const int charsPerTile{ 3 }; // in the file io, it takes 3 chars to extract the data for a tile, the first being its ascii symbol then solidity, then type of special tile

			for (int j = 0; j < width * charsPerTile - 1; j += charsPerTile)  // iterate through each line from left to right
				tiles[(i * width) + j / charsPerTile].init(tm, width, height, (i * width) + j / charsPerTile, line.at(j), line.at(j + 1) - ' ', line.at(j + 2));	// ' ' means its not solid, anything else means its solid, like '.'
		}
	}
}

void TileMap::draw(Window& window)
{
	for (int i = 0; i < width * height; ++i)
		tiles[i].draw(window);
}
