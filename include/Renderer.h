#ifndef RENDERER_H
#define RENDERER_H

#include "Ant.h"
#include "Grid.h"

class Renderer {
    int gridSize;
    float cellSize;
public:
    explicit Renderer(int gridSize);
    void render(Grid& grid, Ant& ant, sf::RenderWindow& window) const;
};

#endif //RENDERER_H
