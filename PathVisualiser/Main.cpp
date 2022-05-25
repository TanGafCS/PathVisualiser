#include "Main.h"
#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

int main()
{
    // instantiate TileMap
    TileMap grid(6, 6);

    // initialise visualiser
    sf::RenderWindow window(sf::VideoMode(screenSideLength, screenSideLength), "SFML works!");

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
        DrawToScreen(window);
    }

    return 0;
}

void DrawToScreen(sf::RenderWindow& window)
{
    sf::Color clearColour(255, 0, 255);
    window.clear(clearColour);
    
    // update visuals of dirty cards

    // draw all visuals

    window.display();
}
