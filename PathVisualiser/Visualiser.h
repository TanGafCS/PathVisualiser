#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "TileMap.h"
class Visualiser
{
public:
	void DrawMatrix(sf::RenderWindow&, const TileMap&);
private:
};

