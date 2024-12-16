#include <SFML/Graphics.hpp>

#ifndef GRID_H
#define GRID_H

#include "Ant.h"
#include <vector>

class Grid {
public:
    Grid(int size);
    void update(Ant& ant);
    int getCell(int x, int y) const;
    int getSize() const;

    void draw(sf::RenderWindow& window) const;

private:
    std::vector<std::vector<int>> grid;

    int width, height;
    std::vector<std::vector<bool>> cells;
    int cellSize = 8;
};

#endif