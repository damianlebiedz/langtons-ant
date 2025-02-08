#include <SFML/Graphics.hpp>
#include "Grid.h"

Grid::Grid(const int size) : grid(size, std::vector<int>(size, 0)), width(0), height(0) {}

void Grid::update(Ant& ant) {
    int x = ant.getX();
    int y = ant.getY();

    if (grid[y][x] == 0) {
        ant.turnRight();
        grid[y][x] = 1;
    } else {
        ant.turnLeft();
        grid[y][x] = 0;
    }

    ant.moveForward();
}

int Grid::getCell(int x, int y) const {
    return grid[y][x];
}

int Grid::getSize() const {
    return grid.size();
}

bool Grid::isClicked(const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        return true;
    }
    return false;
}