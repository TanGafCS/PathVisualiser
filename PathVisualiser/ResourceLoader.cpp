#include "ResourceLoader.h"
// Load resources into map
ResourceLoader::ResourceLoader()
{
    // Read file in "string : filePath" format.
}

sf::Texture ResourceLoader::getTexture(std::string id)
{
    return resourceMap[id];
}
