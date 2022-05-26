#include "ResourceLoader.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

// Load resources into map
ResourceLoader::ResourceLoader()
{
    LoadTextures();
}

void ExtractTokens(std::string& line, std::string& resourceName, std::string& resourcePath)
{
    auto end = std::remove_if(line.begin(), line.end(), isspace);
    line.erase(end, line.end());
    int findIndex = line.find(ResourceLoader::resourceDelimiter);
    resourceName = line.substr(0, findIndex);
    resourcePath = line.substr(findIndex + 1, line.size() - findIndex);
}

void ResourceLoader::LoadTextures()
{
    // Read file in "string : filePath" format.
    std::string line;
    std::ifstream resourceStream("Resources.txt");

    std::string resourceName, resourcePath;
    while (std::getline(resourceStream, line))
    {
        if (line[0] == '#') continue;   // skip comment lines
        // Extract texture name and path
        ExtractTokens(line, resourceName, resourcePath);
        // Load texture and add to resourceMap;
        sf::Texture texture;
        texture.loadFromFile("Resources/" + resourcePath);
        resourceMap.insert({resourceName, texture});
    }
}

sf::Texture& ResourceLoader::GetTexture(std::string id)
{
    return resourceMap[id];
}
