#pragma once
#include "Tile.h"
class TileRect
{
public:
	TileRect(Tile* tile, sf::FloatRect rect);
	Tile* tile;
	sf::FloatRect rect;
};