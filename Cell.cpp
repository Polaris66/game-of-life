#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Grid.hpp"
#include "Headers/Cell.hpp"

Cell::Cell()
{
}

Cell::Cell(int i, int j, int base_x, int base_y, float size)
{
    x = i;
    y = j;
    alive = rand() % 2;
    shape = sf::RectangleShape(sf::Vector2f(size, size));
    shape.setPosition(base_x + i * size, base_y + j * size);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color(255, 255, 255));
}

void Cell::render()
{
    if (alive)
    {
        shape.setFillColor(sf::Color(255, 255, 255, 150));
    }
    else
    {
        shape.setFillColor(sf::Color(0, 0, 0, 0));
    }
}

void Cell::setNeighbors(int _neighbors)
{
    neighbors = _neighbors;
}

void Cell::toggle()
{
    alive = !alive;
    render();
}

void Cell::kill()
{
    alive = false;
    render();
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