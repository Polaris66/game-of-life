#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstring>

#include "Headers/Grid.hpp"
#include "Headers/Cell.hpp"

Grid::Grid(int _size, int base_x, int base_y, int _x, int _y)
{
    size = _size;
    x = _x;
    y = _y;

    cells = new Cell[x * y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cells[y * i + j] = Cell(i, j, base_x, base_y, size);
        }
    }
}

Cell *Grid::getCell(int xpos, int ypos)
{
    if (xpos > x || ypos > y || xpos < 0 || ypos < 0)
    {
        return nullptr;
    }
    return cells + (y * xpos + ypos);
}

void Grid::setNeighbors(int xpos, int ypos)
{
    int neighbors = 0;
    for (int i = xpos - 1; i <= xpos + 1; i++)
    {
        for (int j = ypos - 1; j <= ypos + 1; j++)
        {
            if (!(xpos == i && ypos == j))
            {
                Cell *cell = getCell(i, j);
                if (cell)
                {
                    neighbors += cell->alive;
                }
            }
        }
    }

    getCell(xpos, ypos)->setNeighbors(neighbors);
}

void Grid::update()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            setNeighbors(i, j);
            getCell(i, j)->update();
        }
    }
}

void Grid::clear()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            getCell(i, j)->kill();
        }
    }
}

void Grid::toggle(int xpos, int ypos)
{
    getCell(xpos / size, ypos / size)->toggle();
}

void Grid::render(sf::RenderWindow &window)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            Cell *cell = getCell(i, j);
            cell->render();
            window.draw(cell->shape);
        }
    }
}