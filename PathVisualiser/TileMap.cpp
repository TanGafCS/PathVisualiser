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

std::vector<Tile*> TileMap::GetNeighbours(Tile& tile)
{
	int x = tile.x;
	int y = tile.y;
	std::vector<Tile*> neighbours;
	int rows, cols;
	std::tie(rows, cols) = this->Size();

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (i == y && j == x) continue;
			if (i >= 0 && i < rows && j >= 0 && j < cols)
			{
				neighbours.push_back(&tiles[i][j]);
			}
		}
	}

	return neighbours;
}

std::pair<int, int> TileMap::Size() const
{
	return {tiles.size(), tiles[0].size()};
}

std::vector<Tile> TileMap::operator[](int index) const
{
	return tiles[index];
}

//std::vector<std::vector<Tile>> tiles;