#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ant.h"
#include "Grid.h"
#include "Renderer.h"

int main() {
    constexpr int windowWidth = 600;
    constexpr int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Langton's ant", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../assets/Roboto-Regular.ttf")) {
        return -1;
    }

    sf::Text stepText;
    stepText.setFont(font);
    stepText.setCharacterSize(24);
    stepText.setFillColor(sf::Color::Black);
    stepText.setPosition( 20.f, 20.f);

    constexpr int gridSize = 101;

    int antStartX = gridSize / 2;
    int antStartY = gridSize / 2;

    Grid grid(gridSize);
    Ant ant(antStartX, antStartY);
    Renderer renderer(gridSize);

    bool paused = false;
    int steps = 0;
    float timeSpeed = 10000;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (grid.isClicked(event)) {
                paused = !paused;
            }
        }
        if (!paused) {
            if (clock.getElapsedTime().asSeconds() >= (1.0f / timeSpeed)) {
                grid.update(ant);
                steps++;
                clock.restart();
            }
        }
        window.clear();
        renderer.render(grid, ant, window);

        stepText.setString(std::to_string(steps));
        window.draw(stepText);
        std::cout<<ant.getX()<<" " <<ant.getY()<<std::endl;

        window.display();
    }
    return 0;
}