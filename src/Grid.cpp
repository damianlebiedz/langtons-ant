#include "Grid.h"
#include "Ant.h"
#include <SFML/Graphics.hpp>

Grid::Grid(const int size): grid(size, std::vector<int>(size, 0)) {}

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
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
        throw std::out_of_range("Cell coordinates are out of bounds");
    }
    return grid[y][x];
}