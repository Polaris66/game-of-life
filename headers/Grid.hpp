#pragma once
#include "Cell.hpp"
class Grid
{
private:
    int x, y;
    Cell *cells = nullptr;

public:
    int size;
    Grid(int _size, int _x, int _y);

    void update();
    void render(sf::RenderWindow &window);

    Cell *getCell(int xpos, int ypos);
};