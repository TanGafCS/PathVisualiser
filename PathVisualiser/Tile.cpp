#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int x, int y, sf::Texture& texture)
	: x(x), y(y), texture(&texture), fCost(INT_LEAST16_MAX)
{}
