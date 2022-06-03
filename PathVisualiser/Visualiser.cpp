#include "Visualiser.h"
#include "Main.h"
#include "ResourceLoader.h"
#include <iostream>

void Visualiser::DrawMap(sf::RenderWindow& window, TileMap& tileMap)
{
	activeTiles.clear();

	auto loader = ResourceLoader::Instance();
	// Scale tiles to fit the screen. Scaled on X axis, assuming X and Y are equal.
	int rows, cols;
	std::tie(rows, cols) = tileMap.Size();
	float tileSizeDefault = 64.f;
	float innerTileMult = 0.05f;
	float margin = 5.f;
	float screenLen = screenSideLength;
	float effectiveScreenLen = screenLen - margin * 2;	// The area of the screen available to us
	float interTileMargin = (effectiveScreenLen * innerTileMult);	// The length of 
	int gaps = cols - 1;
	float gapLen = (effectiveScreenLen * innerTileMult) / (cols - 1); // The gaps we need after each tile drawn
	float tileLen = (effectiveScreenLen - interTileMargin) / cols;
	float scale = tileLen / tileSizeDefault;

	// Place tiles onto screen.
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			Tile& tile = tileMap[row][col];
			if (tile.isClosed)
			{
				tile.texture = &loader.GetTexture("closedTile");
			}
			else if (tileMap[row][col].isObstacle)
			{
				tile.texture = &loader.GetTexture("obstacleTile");
			}
			else
			{
				tile.texture = &loader.GetTexture("defaultTile");
			}

			// prepare tile
			float x = margin + (col * (tileLen + gapLen));
			float y = margin + (row * (tileLen + gapLen));
			sf::Texture& tex = *tile.texture;
			sf::Sprite sprite;
			sprite.setTexture(tex);
			sprite.setScale(scale, scale);
			sprite.setPosition(sf::Vector2f(x, y));
			activeTiles.push_back(TileRect(&tile, sprite.getGlobalBounds()));

			window.draw(sprite);
			
			// prepare text
			DrawCost(tile, tileLen, x, y, window, 0.4, 0.5, 0.5, std::to_string(tile.fCost));
			DrawCost(tile, tileLen, x, y, window, 0.225, 0.9, 1.08, std::to_string(tile.hCost));
			DrawCost(tile, tileLen, x, y, window, 0.225, 0.1, 1.08, std::to_string(tile.gCost));
		}
	}
}

void Visualiser::DrawCost(Tile& tile, float tileLen, float x, float y, sf::RenderWindow& window, float fontSizeMult, float xOffset, float yOffset, std::string str)
{

	if (tile.fCost != INT_LEAST16_MAX)
	{
		float textFontSize = tileLen * fontSizeMult;
		sf::Text text(str, font, textFontSize);
		auto textBox = text.getLocalBounds();
		auto freeTileSpaceX = tileLen - textBox.width;
		auto freeTileSpaceY = tileLen - textBox.height;
		text.setPosition(x + (freeTileSpaceX * xOffset) - textBox.left,
			y - ((textFontSize + textBox.top) * yOffset) + tileLen * yOffset);

		window.draw(text);
	}
}

Tile& Visualiser::GetTile(int x, int y)
{
	sf::FloatRect mouseRect(x, y, 1, 1);
	for (auto i = 0; i < activeTiles.size(); i++)
	{
		TileRect& tr = activeTiles[i];
		if (tr.rect.intersects(mouseRect))
		{
			return *tr.tile;
		}
	}
	return NullTile;
}

Visualiser::Visualiser()
	: NullTile()
{
	font = ResourceLoader::Instance().GetFont();
}

TileRect::TileRect(Tile* tile, sf::FloatRect rect)
	:	tile(tile), rect(rect)
{
}
