#include "Renderer.h"

Renderer::Renderer(int gridSize)
    : window(sf::VideoMode(gridSize * 5, gridSize * 5), "Langton's Ant"), cell(sf::Vector2f(5, 5)), cellSize(5) {}

void Renderer::render(const Grid& grid, const Ant& ant) {
    window.clear();

    for (int y = 0; y < grid.getSize(); ++y) {
        for (int x = 0; x < grid.getSize(); ++x) {
            cell.setPosition(x * cellSize, y * cellSize);
            cell.setFillColor(grid.getCell(x, y) == 0 ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }
    }

    // Draw the ant in red
    cell.setPosition(ant.getX() * cellSize, ant.getY() * cellSize);
    cell.setFillColor(sf::Color::Red);
    window.draw(cell);

    window.display();
}
