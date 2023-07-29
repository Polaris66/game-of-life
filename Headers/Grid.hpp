#pragma once

#include "Cell.hpp"
class Grid
{
private:
    int x, y;
    int size;
    Cell *cells = nullptr;

public:
    Grid(int _size, int base_x, int base_y, int _x, int _y);
    ~Grid();

    void update();
    void render(sf::RenderWindow &window);

    Cell *getCell(int xpos, int ypos);
    void setNeighbors(int xpos, int ypos);
};
