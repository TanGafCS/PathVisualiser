#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "TileMap.h"
#include "TileRect.h"
//#include <SFML/Graphics/Rect.hpp>
class Visualiser
{
public:
	void DrawMap(sf::RenderWindow&, TileMap&);
	void DrawCost(Tile& tile, float tileLen, float x, float y, sf::RenderWindow& window,
		float fontSizeMult, float xOffset, float yOffset, std::string str);
	Tile& GetTile(int x, int y);
	Visualiser();
private:
	sf::Font font;
	std::vector<TileRect> activeTiles;
	Tile NullTile;
};