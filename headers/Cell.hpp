#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
private:
    bool nextAliveState;

public:
    sf::RectangleShape shape;
    bool alive;
    void update();

    Cell();
    Cell(int i, int j, float size);
};
