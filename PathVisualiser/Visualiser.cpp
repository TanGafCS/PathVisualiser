#include "Visualiser.h"
#include "Main.h"
#include "ResourceLoader.h"
#include <iostream>

void Visualiser::DrawMatrix(sf::RenderWindow& window, const TileMap& tileMap)
{
	// Dynamically scale tiles to fit the screen
	int rows, cols;
	std::tie(rows, cols) = tileMap.Size();
	std::cout << cols << "\n";
	float tileSizeDefault = 64.f;
	float innerTileMult = 0.05f;
	float marginX = 5.f, marginY = 5.f;
	auto screenSize = window.getSize();
	float screenX = screenSize.x;
	float screenY = screenSize.y;
	std::cout << screenX << ", " << screenY << "\n";
	float effectiveScreenX = screenX - marginX * 2;	// The area of the screen available to us
	float interTileMarginX = (effectiveScreenX * innerTileMult);	// The length of 
	int gaps = cols - 1;
	float gapLen = (effectiveScreenX * innerTileMult) / (cols - 1); // The gaps we need after each tile drawn
	float tileLen = (effectiveScreenX - interTileMarginX) / cols;
	//ResourceLoader& resources = ResourceLoader::Instance();

	float scale = tileLen / tileSizeDefault;

	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			float x = marginX + (col * (tileLen + gapLen));
			float y = marginY + (row * (tileLen + gapLen));
			sf::Texture& tex = tileMap[row][col].texture;
			sf::Sprite sprite;
			sprite.setTexture(tex);
			sprite.setScale(scale, scale);
			sprite.setPosition(sf::Vector2f(x, y));
			window.draw(sprite);
		}
	}
}
