#pragma once
#include "Tile.h"

class TileMap
{
public:
	TileMap(int cols, int rows);
	//~TileMap();
	std::vector<Tile*> GetNeighbours(Tile& tile);
	std::pair<int, int> Size() const;	//Return rows, columns pair
	int Rows();
	int Cols();
	std::vector<Tile>& operator[](int);
private:
	std::vector<std::vector<Tile>> tiles;
};