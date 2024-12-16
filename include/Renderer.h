#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Renderer {

private:
    int gridSize;
    float cellSize;

public:
    Renderer(int gridSize);
    void render(Grid& grid, Ant& ant, sf::RenderWindow& window);
};

#endif // RENDERER_H
