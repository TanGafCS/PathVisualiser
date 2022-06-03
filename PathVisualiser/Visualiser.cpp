#include "Visualiser.h"
#include "Main.h"
#include "ResourceLoader.h"
#include <iostream>

void Visualiser::DrawMatrix(sf::RenderWindow& window, TileMap& tileMap)
{
	auto loader = ResourceLoader::Instance();
	// Scale tiles to fit the screen. Scaled on X axis, assuming X and Y are equal.
	int rows, cols;
	std::tie(rows, cols) = tileMap.Size();
	float tileSizeDefault = 64.f;
	float innerTileMult = 0.05f;
	float margin = 5.f;
	auto screenSize = window.getSize();
	float screenLen = screenSize.x;
	float effectiveScreenLen = screenLen - margin * 2;	// The area of the screen available to us
	float interTileMargin = (effectiveScreenLen * innerTileMult);	// The length of 
	int gaps = cols - 1;
	float gapLen = (effectiveScreenLen * innerTileMult) / (cols - 1); // The gaps we need after each tile drawn
	float tileLen = (effectiveScreenLen - interTileMargin) / cols;
	//ResourceLoader& resources = ResourceLoader::Instance();

	float scale = tileLen / tileSizeDefault;
	// Place tiles onto screen.
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (tileMap[row][col].isClosed)
			{
				tileMap[row][col].texture = &loader.GetTexture("closedTile");
			}

			// prepare tile
			float x = margin + (col * (tileLen + gapLen));
			float y = margin + (row * (tileLen + gapLen));
			sf::Texture& tex = *tileMap[row][col].texture;
			sf::Sprite sprite;
			sprite.setTexture(tex);
			sprite.setScale(scale, scale);
			sprite.setPosition(sf::Vector2f(x, y));

			// prepare text
			float textFontSize = tileLen * 0.3;
			std::string fCostStr = std::to_string(tileMap[row][col].fCost);
			sf::Text text(fCostStr, font, textFontSize);
			auto textBox = text.getLocalBounds();
			auto freeTileSpaceX = tileLen - textBox.width;
			auto freeTileSpaceY = tileLen - textBox.height;
			text.setPosition(x + (freeTileSpaceX / 2) - textBox.left,
							y - ((textFontSize + textBox.top) / 2) + tileLen/2);

			window.draw(sprite);
			window.draw(text);
		}
	}
}

Visualiser::Visualiser()
{
	font = ResourceLoader::Instance().GetFont();
}
