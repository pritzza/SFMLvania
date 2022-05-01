#include "TileMap.h"

#include "Tile.h"

#include "../util/Window.h"
#include "../util/LevelParser.h"

#include "../levels/TileData.h"

#include <fstream>
#include <istream>
#include <string>

#include <iostream>

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

		this->tiles = std::unique_ptr<Tile[]>(new Tile[width * height]);

		LevelParser parser;

		for (int i = 0; i < height; ++i)
		{
			std::getline(file, line);   // iterate through all of the file's lines from top to bottom
			const int charsPerTile{ 3 }; // in the file io, it takes 3 chars to extract the data for a tile, the first being its ascii symbol then solidity, then type of special tile

			for (int j = 0; j < width * charsPerTile - 1; j += charsPerTile)  // iterate through each line from left to right
			{
				const int index = (i * width) + j / charsPerTile;

				unsigned int sprite{ TILE_SPRITE_ID::AIR };
				TILE_SOLID solid{ TILE_SOLID::NOT_SOLID };
				TILE_SPECIAL special{ TILE_SPECIAL::NONE };

				try		// if something wrong with format of level data going in, replace corrupt data with default tiles
				{
					sprite = parser.parseSpriteID(	parser.getSpriteIndex(	line.at(j)));
					solid = parser.parseSolid(		parser.getSolidIndex(	line.at(j + 1)));
					special = parser.parseSpecial(	parser.getSpecialIndex(	line.at(j + 2)));
				}
				catch (...)
				{
					std::cout << "parsing error";
				}

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

		LevelParser parser;

		for (int i = 0; i < width * height; ++i)
		{
			if (i % width == 0 && i)
				file << '\n';

			file <<
				parser.unparseSpriteID(	parser.getIndex(tiles[i].getSpriteID())) <<
				parser.unparseSolid(	parser.getIndex(tiles[i].getSolid())) <<
				parser.unparseSpecial(	parser.getIndex(tiles[i].getSpecial()));
		}

		file.close();
	}
}

Tile& TileMap::getTile(const unsigned int index)
{
	if (index > 0 && index < width * height)
		return tiles[index];
	
	return tiles[0];
}

Tile& TileMap::getTile(const int x, const int y)
{
	const int& ts = tiles[0].getSize();
	const int& index = (x / ts) % width + ((y / ts) * width);
	
	return this->getTile(index);
}

const unsigned int TileMap::getWidth() const
{
	return this->width;
}

const unsigned int TileMap::getHeight() const
{
	return this->height;
}

void TileMap::draw(Window& window, const bool drawRect)
{
	for (int i = 0; i < width * height; ++i)
		tiles[i].draw(window, drawRect);
}

void TileMap::draw(Window& window)
{
	for (int i = 0; i < width * height; ++i)
		tiles[i].draw(window);
}
