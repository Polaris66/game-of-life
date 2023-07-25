#include <cstring>
#include "headers/Cell.hpp"
#include "headers/Grid.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Grid::Grid(int _size, int _x, int _y)
{
    size = _size;
    x = _x;
    y = _y;

    cells = new Cell[x * y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cells[y * i + j] = Cell(i, j, size);
        }
    }
}

Cell *Grid::getCell(int xpos, int ypos)
{
    return cells + (y * xpos + ypos);
}

void Grid::update()
{
}

void Grid::render(sf::RenderWindow &window)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            window.draw(cells[i * y + j].shape);
        }
    }
}