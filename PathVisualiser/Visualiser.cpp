#include "Visualiser.h"
#include "Main.h"
#include "ResourceLoader.h"

void Visualiser::DrawMatrix(sf::RenderWindow& window, const TileMap& tileMap)
{
	int rows, cols;
	std::tie(rows, cols) = tileMap.Size();
	//ResourceLoader& resources = ResourceLoader::Instance();

	int marginPerTile = screenSideLength / rows;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			int y = row * marginPerTile;
			int x = col * marginPerTile;
			sf::Texture& tex = tileMap[row][col].texture;
			sf::Sprite sprite;
			sprite.setTexture(tex);
			sprite.setPosition(sf::Vector2f((float)x, (float)y));
			window.draw(sprite);
		}
	}
}
