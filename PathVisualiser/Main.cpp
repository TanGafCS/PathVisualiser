#include "Main.h"
#include "TileMap.h"
#include "Visualiser.h"

int main()
{
    // initialise visualiser
    sf::RenderWindow window(sf::VideoMode(screenSideLength, screenSideLength), "SFML works!", sf::Style::Close);
    Visualiser visualiser;

    // instantiate TileMap
    TileMap tileMap(16, 16);

    while (window.isOpen())
    {
        // Handle Inputs
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Run logic updates
        

        // Draw black bg
        sf::Color clearColour(0, 0, 0);
        window.clear(clearColour);

        visualiser.DrawMatrix(window, tileMap);

        window.display();
    }

    return 0;
}
