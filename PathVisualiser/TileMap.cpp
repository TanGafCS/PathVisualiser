#include "TileMap.h"

TileMap::TileMap(int cols, int rows)
{
	for (int y = 0; y < cols; y++)
	{
		for (int x = 0; x < rows; x++)
		{
			tiles.emplace_back(Tile(x, y));
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