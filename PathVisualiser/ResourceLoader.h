#pragma once
#include <sfml/Graphics.hpp>
#include <unordered_map>

enum ResourceID
{
	DefaultTile = 1
};

class ResourceLoader
{
public:
	// Singleton
	static ResourceLoader& instance()
	{
		static ResourceLoader instance;
		return instance;
	}
	ResourceLoader(ResourceLoader const&) = delete;
	void operator=(ResourceLoader const&) = delete;
	
	// Resource loading
	sf::Texture getTexture(std::string id);
private:
	ResourceLoader();
	static ResourceLoader* instance;
	std::unordered_map<std::string, sf::Texture> resourceMap;
};

