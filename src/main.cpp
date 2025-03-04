#include <SFML/Graphics.hpp>
#include "Ant.h"
#include "Grid.h"
#include "Renderer.h"

void handleEvents(sf::RenderWindow& window, bool& paused) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            paused = !paused;
        }
    }
}

void update(Grid& grid, Ant& ant, int& steps, sf::Clock& clock, const float timeSpeed) {
    if (clock.getElapsedTime().asSeconds() >= (1.0f / timeSpeed)) {
        grid.update(ant);
        steps++;
        clock.restart();
    }
}

void render(const Renderer& renderer, Grid& grid, Ant& ant, sf::RenderWindow& window, const sf::Text& stepText) {
    window.clear();
    renderer.render(grid, ant, window);
    window.draw(stepText);
    window.display();
}

int main() {
    constexpr int windowWidth = 600;
    constexpr int windowHeight = 600;
    constexpr int gridSize = 101;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Langton's Ant", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../assets/Roboto-Regular.ttf")) {
        return -1;
    }

    sf::Text stepText;
    stepText.setFont(font);
    stepText.setCharacterSize(24);
    stepText.setFillColor(sf::Color::Black);
    stepText.setPosition(20.f, 20.f);

    constexpr int antStartX = gridSize / 2;
    constexpr int antStartY = gridSize / 2;

    Grid grid(gridSize);
    Ant ant(antStartX, antStartY);
    Renderer renderer(gridSize);

    bool paused = false;
    int steps = 0;

    sf::Clock clock;

    while (window.isOpen()) {
        handleEvents(window, paused);
        if (!paused) {
            float timeSpeed = 10000;
            update(grid, ant, steps, clock, timeSpeed);
        }
        render(renderer, grid, ant, window, stepText);
        stepText.setString("Steps: " + std::to_string(steps));
    }
    return 0;
}