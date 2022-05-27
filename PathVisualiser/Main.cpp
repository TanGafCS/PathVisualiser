#include "Main.h"
#include "TileMap.h"
#include "Visualiser.h"

int main()
{
    // initialise visualiser
    Visualiser visualiser;
    sf::RenderWindow window(sf::VideoMode(screenSideLength, screenSideLength), "SFML works!");

    // instantiate TileMap
    TileMap tileMap(6, 6);

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
        

        // Draw
        sf::Color clearColour(255, 0, 255);
        window.clear(clearColour);

        visualiser.DrawMatrix(window, tileMap);

        window.display();
    }

    return 0;
}
