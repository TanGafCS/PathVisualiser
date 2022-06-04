#include "Main.h"
#include "TileMap.h"
#include "Visualiser.h"
#include "AStar.h"
#include <iostream>

int main()
{
    // initialise visualiser
    sf::RenderWindow window(sf::VideoMode(screenSideLength + uiScreenLength, screenSideLength), "Pathfinding Visualiser", sf::Style::Close);
    window.setKeyRepeatEnabled(false);
    Visualiser visualiser;

    // instantiate TileMap
    int rows, cols;
    rows = cols = 6;
    TileMap tileMap(rows, cols);
    Pathfinder* pathfinder;
    AStar aStar(tileMap, &tileMap[0][0], &tileMap[rows-1][cols-1]);
    pathfinder = &aStar;
    
    //float delay = 0.3f;
    //sf::Clock clock;
    //sf::Time start = clock.getElapsedTime();

    while (window.isOpen())
    {
        //sf::Time timeSinceLastTick = clock.getElapsedTime();
        //if (timeSinceLastTick.asSeconds() - start.asSeconds() > delay)
        //{
        //    clock.restart();
        //    pathfinder->Step();
        //}

        // Handle Inputs
        sf::Event event;
        auto mPos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle tile-related inputs
            Tile& hoverTile = visualiser.GetTile(mPos.x, mPos.y);
            if (event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::N)
                {
                    pathfinder->Step();
                    std::cout << pathfinder->IsGoalFound() << std::endl;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    pathfinder->startTile = &hoverTile;
                    pathfinder->Reset();
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    pathfinder->goalTile = &hoverTile;
                    pathfinder->Reset();
                }
            }
            else if (event.type == sf::Event::EventType::MouseButtonPressed)
            {
                hoverTile.isObstacle = !hoverTile.isObstacle;
                pathfinder->Reset();
            }
        }

        // Draw black bg
        sf::Color clearColour(0, 0, 0);
        window.clear(clearColour);

        visualiser.DrawMap(window, tileMap, *pathfinder);

        window.display();
    }

    return 0;
}
