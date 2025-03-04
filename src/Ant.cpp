#include "Ant.h"

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

int Ant::getX() const { return x; }

int Ant::getY() const { return y; }
