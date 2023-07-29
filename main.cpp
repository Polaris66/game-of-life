#include <SFML/Graphics.hpp>
#include <chrono>

#include "Headers/Grid.hpp"

int main()
{
    // Global Variables
    int windowWidth = 700;
    int windowHeight = 700;

    int sideBarGap = 50;
    int titleHeight = 75;

    int width = 600;
    int height = 600;

    int size = 40;

    // Game Variables
    bool paused = false;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
    window.setKeyRepeatEnabled(false);

    // Create Grid
    int x = width / size;
    int y = height / size;

    Grid grid(size, sideBarGap, titleHeight, x, y);

    // Create Font
    sf::Font font;
    font.loadFromFile("font.ttf");

    // Title Text
    sf::Text title;
    title.setFont(font);
    title.setString("Game Of Life");
    title.setCharacterSize(32);
    title.setPosition(windowWidth / 2 - 100, 15);

    // Create Clock
    sf::Clock clock;
    double timeBetweenFrames = 1.0;
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

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    paused = !paused;
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    grid = Grid(size, sideBarGap, titleHeight, x, y);
                }
                if (event.key.code == sf::Keyboard::C)
                {
                    grid.clear();
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    timeBetweenFrames /= 2;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    timeBetweenFrames *= 2;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int xpos = event.mouseButton.x;
                    int ypos = event.mouseButton.y;

                    if ((xpos >= sideBarGap) && (xpos <= sideBarGap + width) && (ypos >= titleHeight) && (ypos <= titleHeight + height))
                    {
                        grid.toggle(xpos - sideBarGap, ypos - titleHeight);
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        // Draw Text
        window.draw(title);

        if (clock.getElapsedTime().asSeconds() > timeBetweenFrames && !paused)
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