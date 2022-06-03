#include "Main.h"
#include "TileMap.h"
#include "Visualiser.h"
#include "AStar.h"
#include <iostream>

int main()
{
    // initialise visualiser
    sf::RenderWindow window(sf::VideoMode(screenSideLength, screenSideLength), "Pathfinding Visualiser", sf::Style::Close);
    window.setKeyRepeatEnabled(false);
    Visualiser visualiser;

    // instantiate TileMap
    int rows = 8, cols = 8;
    TileMap tileMap(8, 8);
    Pathfinder* pathfinder;
    AStar aStar(tileMap, &tileMap[0][0], &tileMap[rows-1][cols-1]);
    pathfinder = &aStar;
    tileMap[5][5].isObstacle = true;
    tileMap[4][5].isObstacle = true;
    tileMap[6][5].isObstacle = true;

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

        visualiser.DrawMap(window, tileMap);

        window.display();
    }

    return 0;
}
