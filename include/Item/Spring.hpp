#pragma once

#include <SFML/Graphics.hpp>

class Spring
{
public:
    Spring(float x, float y);

    void draw(sf::RenderWindow& window) const;

    sf::FloatRect getBounds() const;

    sf::Vector2f getPosition() const;

    void setPosition(float x, float y);

    bool isUsed() const;

    void use();

    void reset();

private:
    sf::Sprite sprite;
    bool used = false;
};
