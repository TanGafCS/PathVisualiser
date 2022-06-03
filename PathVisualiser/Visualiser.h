#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "TileMap.h"
class Visualiser
{
public:
	void DrawMap(sf::RenderWindow&, TileMap&);
	void DrawCost(Tile& tile, float tileLen, float x, float y, sf::RenderWindow& window,
		float fontSizeMult, float xOffset, float yOffset, std::string str);
	Visualiser();
private:
	sf::Font font;
};

