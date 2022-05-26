#include "TileMap.h"
#include "ResourceLoader.h"
#include <iostream>

TileMap::TileMap(int cols, int rows)
{
	ResourceLoader& loader = ResourceLoader::Instance();
	sf::Texture& defaultTex = loader.GetTexture("defaultTile");

	tiles.reserve(rows);
	for (int y = 0; y < cols; y++)
	{
		//std::vector<Tile> tileVec;
		tiles.emplace_back();
		tiles[y].reserve(cols);
	}

	for (int y = 0; y < cols; y++)
	{
		for (int x = 0; x < rows; x++)
		{
			tiles[y].emplace_back(x, y, defaultTex);
		}
	}
}

//TileMap::~TileMap()
//{
//	delete tiles;
//}

std::vector<Tile>& TileMap::operator[](int index)
{
	return tiles[index];
}

//std::vector<std::vector<Tile>> tiles;