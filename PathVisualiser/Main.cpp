#include "Main.h"
#include "TileMap.h"
#include "Visualiser.h"
#include "AStar.h"
#include <iostream>

int main()
{
    // initialise visualiser
    sf::RenderWindow window(sf::VideoMode(screenSideLength, screenSideLength), "SFML works!", sf::Style::Close);
    window.setKeyRepeatEnabled(false);
    Visualiser visualiser;

    // instantiate TileMap
    TileMap tileMap(12, 12);
    Pathfinder* pathfinder;
    AStar aStar(tileMap, &tileMap[0][0], &tileMap[11][11]);
    pathfinder = &aStar;
    //AStar pathfinder(tileMap, &tileMap[0][0], &tileMap[11][11]);

    while (window.isOpen())
    {
        // Handle Inputs
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    pathfinder->Step();
                    std::cout << pathfinder->IsGoalFound() << std::endl;
                }
            }
        }

        // Draw black bg
        sf::Color clearColour(0, 0, 0);
        window.clear(clearColour);

        visualiser.DrawMatrix(window, tileMap);

        window.display();
    }

    return 0;
}
