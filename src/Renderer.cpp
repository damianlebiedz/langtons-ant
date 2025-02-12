#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include <cstdint>
#include <cstdlib>

Renderer::Renderer(int gridSize) : gridSize(gridSize), cellSize(600.0f / gridSize) {}

void Renderer::render(Grid& grid, Ant& ant, sf::RenderWindow& window) {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            cell.setPosition(x * cellSize, y * cellSize);
            cell.setFillColor(grid.getCell(x, y) == 0 ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }
    }
    sf::RectangleShape antShape(sf::Vector2f(cellSize, cellSize));
    antShape.setPosition(ant.getX() * cellSize, ant.getY() * cellSize);
    antShape.setFillColor(sf::Color::Red);
    window.draw(antShape);
}