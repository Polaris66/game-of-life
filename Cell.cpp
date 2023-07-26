#include <SFML/Graphics.hpp>

#include "Headers/Grid.hpp"
#include "Headers/Cell.hpp"

Cell::Cell()
{
}

Cell::Cell(int i, int j, float size)
{
    x = i;
    y = j;
    alive = rand() % 2;
    shape = sf::RectangleShape(sf::Vector2f(size, size));
    shape.setPosition(i * size, j * size);
}

void Cell::render()
{
    if (alive)
    {
        shape.setFillColor(sf::Color::White);
    }
    else
    {
        shape.setFillColor(sf::Color::Black);
    }
}

void Cell::setNeighbors(int _neighbors)
{
    neighbors = _neighbors;
}

void Cell::update()
{

    if (neighbors > 3 && alive)
    {
        alive = false;
    }
    else if (neighbors == 3 and !alive)
    {
        alive = true;
    }
    else if (neighbors < 2 && alive)
    {
        alive = false;
    }
}