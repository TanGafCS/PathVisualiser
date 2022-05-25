#pragma once
#include <SFML/Graphics.hpp>

class Tile
{
public:
	int x, y;	// Position
	sf::Texture& texture;
	Tile(int x, int y, sf::Texture&);
	~Tile();
};