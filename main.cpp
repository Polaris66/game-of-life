#include <SFML/Graphics.hpp>

int main()
{
    int width = 800;
    int height = 600;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(width, height), "Game of Life");

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
    }
}