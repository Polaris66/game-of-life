#include "headers/Grid.hpp"
#include <SFML/Graphics.hpp>

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
    // Main Loop
    while (window.isOpen())
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

        grid.render(window);

        // Display Stuff
        window.display();
    }

    return 0;
}