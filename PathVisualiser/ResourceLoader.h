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
	sf::Font& GetFont();

	static const char resourceDelimiter = ':';
	const std::string resourcesPath{ "Resources/" };
private:
	ResourceLoader();
	static ResourceLoader* instance;

	void LoadFont();
	void LoadTextures();
	std::unordered_map<std::string, sf::Texture> resourceMap;
	sf::Font font;
};

