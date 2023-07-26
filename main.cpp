#include <SFML/Graphics.hpp>
#include <chrono>

#include "Headers/Grid.hpp"

int main()
{
    int width = 800;
    int height = 600;

    int size = 40;

    int x = width / size;
    int y = height / size;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(width, height), "Game of Life");

    Grid grid(size, x, y);
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

        if (clock.getElapsedTime().asSeconds() > 0.01f)
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