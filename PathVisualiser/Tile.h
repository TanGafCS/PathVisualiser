#pragma once
#include <SFML/Graphics.hpp>

struct Tile
{
public:
	int x, y;	// Position
	int fCost;
	sf::Texture& texture;
	Tile(int x, int y, sf::Texture&);
	//~Tile();
};