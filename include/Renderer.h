#ifndef RENDERER_H
#define RENDERER_H

#include "Grid.h"
#include "Ant.h"
#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer(int gridSize);
    void render(const Grid& grid, const Ant& ant);

private:
    sf::RenderWindow window;
    sf::RectangleShape cell;
    int cellSize;
};

#endif
