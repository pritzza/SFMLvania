#include "TileMap.h"

#include "Tile.h"

#include "../util/Window.h"

#include <fstream>
#include <istream>
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
			{
				const int index = (i * width) + j / charsPerTile;
				const unsigned int sprite = tiles[0].parseSpriteID(line.at(j));
				TILE_SOLID solid = tiles[0].parseSolid(line.at(j + 1));
				TILE_SPECIAL special = tiles[0].parseSpecial(line.at(j + 2));

				tiles[index].init(tm, width, index, sprite, solid, special);
			}
		}
	}
}

void TileMap::save(const std::string& fileName)
{
	std::ofstream file;
	file.open(fileName);
	if (file.is_open())
	{
		file.clear();
		file << width << '\n' << height << '\n';

		for (int i = 0; i < width * height; ++i)
		{
			if (i % width == 0 && i)
				file << '\n';

			file << tiles[i].unparseSpriteID() << tiles[i].unparseSolid() << tiles[i].unparseSpecial();
		}

		file.close();
	}
}

Tile& TileMap::getTile(const unsigned int index)
{
	return tiles[index];
}

const unsigned int TileMap::getWidth() const
{
	return this->width;
}

const unsigned int TileMap::getHeight() const
{
	return this->height;
}

void TileMap::draw(Window& window)
{
	for (int i = 0; i < width * height; ++i)
		tiles[i].draw(window);
}
