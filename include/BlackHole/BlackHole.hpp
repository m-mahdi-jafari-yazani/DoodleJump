#pragma once

#include <SFML/Graphics.hpp>

enum class BlackHoleType
{
    Small,
    Large
};

class BlackHole
{
public:

    BlackHole(
        BlackHoleType type,
        float x,
        float y
    );

    void draw(
        sf::RenderWindow& window
    ) const;

    void update(float deltaTime);

    sf::FloatRect getBounds() const;

    float getY() const;

    void move(float offset);

private:

    sf::Sprite sprite;

    BlackHoleType type;
};