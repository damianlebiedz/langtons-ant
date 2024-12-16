#include "Button.h"
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Renderer.h"
#include <cmath>

int main() {

    const int windowWidth = 600;
    const int windowHeight = 600;
    const int barHeight = 60;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Langton's Ant", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:/Users/Damia/cpp-langtons-ant/assets/Roboto-Regular.ttf")) {
        return -1;
    }

    sf::Text stepText;
    stepText.setFont(font);
    stepText.setCharacterSize(24);
    stepText.setFillColor(sf::Color::Black);
    stepText.setPosition( 20.f, 20.f);

    sf::Text speedUpText;
    speedUpText.setFont(font);
    speedUpText.setCharacterSize(24);
    speedUpText.setFillColor(sf::Color::Black);
    speedUpText.setPosition(20.f, 60.f);

    sf::RectangleShape bottomBar(sf::Vector2f(windowWidth, barHeight));
    bottomBar.setPosition(0, windowHeight - barHeight);
    bottomBar.setFillColor(sf::Color::Black);

    float buttonWidth = 150;
    float buttonHeight = 30;
    float buttonX = (windowWidth - buttonWidth) / 2;
    float buttonY = windowHeight - barHeight + (barHeight - buttonHeight) / 2;

    Button pauseBtn(buttonX, buttonY, buttonWidth, buttonHeight, sf::Color::White, "Pause");
    pauseBtn.setFont(font);
    Button slowerBtn(buttonX-180, buttonY, buttonWidth, buttonHeight, sf::Color::White, "Slower");
    slowerBtn.setFont(font);
    Button fasterBtn(buttonX+180, buttonY, buttonWidth, buttonHeight, sf::Color::White, "Faster");
    fasterBtn.setFont(font);

    const int gridSize = 101;

    int antStartX = gridSize / 2;
    int antStartY = gridSize / 2;

    Grid grid(gridSize);
    Ant ant(antStartX, antStartY);
    Renderer renderer(gridSize);

    bool paused = true;
    int steps = 0;
    int timeSpeed = 1;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (pauseBtn.isClicked(event)) {
                paused = !paused;
            }
            if (slowerBtn.isClicked(event)) {
                if (timeSpeed > 1) timeSpeed /= 2;
            }
            if (fasterBtn.isClicked(event)) {
                if(timeSpeed < 512) timeSpeed *= 2;
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

        window.draw(bottomBar);

        pauseBtn.draw(window);
        slowerBtn.draw(window);
        fasterBtn.draw(window);

        stepText.setString( "Steps: " + std::to_string(steps));
        window.draw(stepText);

        speedUpText.setString("Speed: " + std::to_string(static_cast<int>(log(timeSpeed) / log(2))+1) + "/10");
        window.draw(speedUpText);

        window.display();
    }
    return 0;
}