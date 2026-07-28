#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float x, float y);

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    bool isOffScreen() const;

    sf::FloatRect getBounds() const;

    bool isAlive() const;

    void destroy();

private:
    sf::CircleShape shape;

    float speed;

    bool alive = true;
};