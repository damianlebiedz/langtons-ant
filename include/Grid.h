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

private:
    std::vector<std::vector<int>> grid;
};

#endif
