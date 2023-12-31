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
    void toggle();
    void kill();
    void setNeighbors(int _neighbors);

    Cell();
    Cell(int i, int j, int base_x, int base_y, float size);
};
