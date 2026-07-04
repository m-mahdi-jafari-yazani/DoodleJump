#pragma once

#include <SFML/Graphics.hpp>

struct PhysicsState
{
    sf::FloatRect previousBounds;
    sf::FloatRect currentBounds;

    float velocityY;
};