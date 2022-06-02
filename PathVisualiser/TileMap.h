#pragma once
#include "Tile.h"

class TileMap
{
public:
	TileMap(int cols, int rows);
	//~TileMap();
	std::vector<Tile*> GetNeighbours(Tile& tile);
	std::pair<int, int> Size() const;	//Return rows, columns pair
	std::vector<Tile> operator[](int) const;
private:
	std::vector<std::vector<Tile>> tiles;
};