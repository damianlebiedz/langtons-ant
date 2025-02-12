#include <SFML/Graphics.hpp>
#include "Ant.h"
#include <cstdint>
#include <cstdlib>

Ant::Ant(int startX, int startY) : x(startX), y(startY), dir(NORTH) {}

void Ant::turnRight() {
    dir = static_cast<Direction>((dir + 1) % 4);
}

void Ant::turnLeft() {
    dir = static_cast<Direction>((dir + 3) % 4);
}

void Ant::moveForward() {
    if (dir == NORTH) --y;
    else if (dir == EAST) ++x;
    else if (dir == SOUTH) ++y;
    else if (dir == WEST) --x;
}

void Ant::draw(sf::RenderWindow& window) const {
    sf::RectangleShape antShape(sf::Vector2f(8, 8));
    antShape.setPosition(x * 8, y * 8);
    antShape.setFillColor(sf::Color::Red);
    window.draw(antShape);
}

int Ant::getX() const { return x; }

int Ant::getY() const { return y; }

Direction Ant::getDirection() const {
    return dir;
}