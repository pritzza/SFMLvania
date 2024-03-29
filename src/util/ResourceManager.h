#pragma once

#include <unordered_map>
#include <memory>

#include <iostream>

enum class TEXTURES
{
	DEFAULT,
	MONKEY,
	TILESET,
	SIMON,
	GOBLIN,
};
enum class FONTS
{
	DEFAULT,
};
enum class SOUNDS
{
	DEFAULT,
};

template <class Key, class Resource>
class ResourceManager
{
private:
	std::unordered_map<Key, std::shared_ptr<Resource>> resources;

private:
	Key addFromFile(const std::string& fileName, const Key resourceID)
	{
		if (resources.find(resourceID) == resources.end())    // if resource is not already loaded
		{
			std::shared_ptr<Resource> r = std::make_shared<Resource>();
			
			if (r->loadFromFile(fileName))
			{
				resources.insert({ resourceID, r });
				return resourceID;    // successfully adds resource to resources under resourceID
			}

			return Key::DEFAULT;    // didnt load sucessfully
		}
		return resourceID;	// already loaded, do nothing
	}

public:
	~ResourceManager()
	{
		clearAll();
	}

	Key add(const TEXTURES resourceID)
	{
		switch (resourceID)
		{
		case TEXTURES::DEFAULT:	return addFromFile("res/sprites/chara_01.png", resourceID);
		case TEXTURES::MONKEY:	return addFromFile("res/sprites/monkeySpriteSheet.png", resourceID);
		case TEXTURES::TILESET:	return addFromFile("res/sprites/tiles.png", resourceID);
		case TEXTURES::SIMON:	return addFromFile("res/sprites/simonSpriteSheet.png", resourceID);
		case TEXTURES::GOBLIN:	return addFromFile("res/sprites/goblinSpriteSheet.png", resourceID);
		}
	}

	Key add(const FONTS resourceID)
	{
		switch (resourceID)
		{
		case FONTS::DEFAULT:	return addFromFile("res/fonts/pokemon_fire_red.ttf", resourceID);
		}
	}

	Key add(const SOUNDS resourceID)
	{
		switch (resourceID)
		{
		case SOUNDS::DEFAULT:	return addFromFile("", resourceID);
		}
	}

	std::shared_ptr<Resource> load(const Key res)
	{
		if (resources.find(res) != resources.end())	// cant load a resource that isnt there
			return resources.at(res);

		return resources.at(Key::DEFAULT);
	}

	void remove(const Key res)
	{
		if (resources.size() && resources.find(res) != resources.end())	// cant delete a resource that isnt there, resources cant be empty either
			resources.erase(res);
	}

	void clearAll()
	{
		for (auto it = resources.begin(); it != resources.end(); )
			it = resources.erase(it);	// increments iterator
	}
};