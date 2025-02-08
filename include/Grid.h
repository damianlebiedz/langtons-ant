#ifndef GRID_H
#define GRID_H

#include "Ant.h"

class Grid {
public:
    Grid(int size);
    void update(Ant& ant);
    int getCell(int x, int y) const;
    int getSize() const;
    bool isClicked(const sf::Event & event);

private:
    std::vector<std::vector<int>> grid;
    int width, height;
    std::vector<std::vector<bool>> cells;
    int cellSize = 8;
};

#endif //GRID_H