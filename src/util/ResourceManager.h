#pragma once

#include <unordered_map>

enum class TEXTURES
{
	DEFAULT,
	MONKEY,
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
	std::unordered_map<Key, Resource*> resources;

private:
	Key addFromFile(const std::string& fileName, const Key resourceID)
	{
		if (resources.find(resourceID) == resources.end())    // if resource is not already loaded
		{
			Resource* r = new Resource;

			if (r->loadFromFile(fileName))
			{
				resources.insert({ resourceID, r });
				return resourceID;    // successfully adds resource to resources under resourceID
			}
		}
		return Key::DEFAULT;    // didnt load sucessfully
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
		}
	}

	Key add(const FONTS resourceID)
	{
		switch (resourceID)
		{
		case FONTS::DEFAULT:	return addFromFile("res/fonts/Roboto-ThinItalic.ttf", resourceID);
		}
	}

	Key add(const SOUNDS resourceID)
	{
		switch (resourceID)
		{
		case SOUNDS::DEFAULT:	return addFromFile("", resourceID);
		}
	}

	Resource* load(const Key res)
	{
		if (resources.find(res) != resources.end())	// cant load a resource that isnt there
			return resources.at(res);

		return resources.at(Key::DEFAULT);
	}

	void remove(const Key res)
	{
		if (resources.find(res) != resources.end())	// cant delete a resource that isnt there
		{
			delete resources.at(res);
			resources.erase(res);
		}
	}

	void clearAll()
	{
		for (auto it = resources.begin(); it != resources.end(); )
		{
			delete it->second;
			it = resources.erase(it);	// increments iterator
		}
	}
};