#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label) {
    button.setSize(sf::Vector2f(width, height));
    button.setPosition(x, y);
    button.setFillColor(color);

    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    text.setPosition(x,y);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

bool Button::isClicked(const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            return true;
        }
    }
    return false;
}

void Button::setFont(const sf::Font& font) {
    text.setFont(font);
}
