#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "TileMap.h"
class Visualiser
{
public:
	void DrawMap(sf::RenderWindow&, TileMap&);
	Visualiser();
private:
	sf::Font font;
};

