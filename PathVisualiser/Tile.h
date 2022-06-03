#pragma once
#include <SFML/Graphics.hpp>

struct Tile
{
public:
	int x, y;	// Position
	int fCost;
	bool isObstacle = false, isClosed = false;
	Tile* predecessor;	// Set when pathing.
	sf::Texture* texture;
	Tile(int x, int y, sf::Texture&);
	//~Tile();
};