#include "Ant.h"
#include "Grid.h"
#include "Renderer.h"

int main() {
    const int gridSize = 101;
    const int steps = 10000;

    Grid grid(gridSize);
    Ant ant(gridSize / 2, gridSize / 2);
    Renderer renderer(gridSize);

    for (int i = 0; i < steps; ++i) {
        grid.update(ant);
        renderer.render(grid, ant);
    }

    return 0;
}