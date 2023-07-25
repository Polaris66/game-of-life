#include <Cell.hpp>

class Grid
{
private:
    Cell *cells = nullptr;

public:
    int width, height;
    Grid(int _width, int _height);
    ~Grid();

    void update();

    Cell &getCell(int xpos, int ypos, int localWidth);
};
