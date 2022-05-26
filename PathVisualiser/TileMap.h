#pragma once
#include "Tile.h"

class TileMap
{
public:
	TileMap(int cols, int rows);
	//~TileMap();
	std::vector<Tile>& operator[](int index);
private:
	std::vector<std::vector<Tile>> tiles;
};