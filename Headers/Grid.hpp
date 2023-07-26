#pragma once

#include "Cell.hpp"
class Grid
{
private:
    int x, y;
    int size;
    Cell *cells = nullptr;

public:
    Grid(int _size, int _x, int _y);

    void update();
    void render(sf::RenderWindow &window);

    Cell *getCell(int xpos, int ypos);
    void setNeighbors(int xpos, int ypos);
};
