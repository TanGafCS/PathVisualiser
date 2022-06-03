#pragma once
#include <SFML/Graphics.hpp>

struct Tile
{
public:
	int x, y;	// Position
	int fCost;
	Tile* predecessor;	// Set when pathing.
	sf::Texture& texture;
	Tile(int x, int y, sf::Texture&);
	//~Tile();
};