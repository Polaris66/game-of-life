#include <SFML/Graphics.hpp>
#include <chrono>

#include "Headers/Grid.hpp"

int main()
{
    int windowWidth = 1200;
    int windowHeight = 800;

    int sideBarWidth = 400;
    int titleHeight = 100;

    int width = 600;
    int height = 600;

    int size = 40;

    int x = width / size;
    int y = height / size;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Game of Life");

    Grid grid(size, sideBarWidth, titleHeight, x, y);
    sf::Clock clock;
    // Main Loop
    while (1 == window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        if (clock.getElapsedTime().asSeconds() > 1.0f)
        {
            grid.update();
            clock.restart();
        }
        grid.render(window);

        // Display Stuff
        window.display();
    }

    return 0;
}