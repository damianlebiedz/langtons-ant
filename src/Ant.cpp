#include <SFML/Graphics.hpp>
#include "Ant.h"

Ant::Ant(int startX, int startY) : x(startX), y(startY), dir(NORTH) {}

void Ant::turnRight() {
    dir = static_cast<Direction>((dir + 1) % 4);
}

void Ant::turnLeft() {
    dir = static_cast<Direction>((dir + 3) % 4);
}

void Ant::moveForward() {
    if (dir == NORTH && y < 55) --y;
    else if (dir == EAST && x < 55) ++x;
    else if (dir == SOUTH && y > 45) ++y;
    else if (dir == WEST && x > 45) --x;
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