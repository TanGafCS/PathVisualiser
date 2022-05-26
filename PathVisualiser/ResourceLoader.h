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
	static ResourceLoader& Instance()
	{
		static ResourceLoader instance;
		return instance;
	}
	
	// Get reference to texture
	sf::Texture& GetTexture(std::string id);

	static const char resourceDelimiter = ':';
	const std::string resourcesPath{ "Resources/" };
private:
	ResourceLoader();
	static ResourceLoader* instance;

	void LoadTextures();
	std::unordered_map<std::string, sf::Texture> resourceMap;
};

