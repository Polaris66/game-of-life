#include "headers/Cell.hpp"
#include <SFML/Graphics.hpp>

Cell::Cell()
{
}

Cell::Cell(int i, int j, float x)
{
    shape = sf::RectangleShape(sf::Vector2f(x, x));
    shape.setPosition(i * x, j * x);
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(1.0f);
    shape.setOutlineColor(sf::Color(255, 0, 0));
}