#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {

private:
    sf::RectangleShape button;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Event &event);
    void setFont(const sf::Font& font);
};

#endif
