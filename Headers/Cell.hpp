#pragma once

class Cell
{
private:
    int x, y;
    int neighbors;

public:
    sf::RectangleShape shape;
    bool alive;
    void render();
    void update();

    void setNeighbors(int _neighbors);

    Cell();
    Cell(int i, int j, float size);
};
