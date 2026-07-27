#pragma once

#include <vector>

#include "BlackHole/BlackHole.hpp"

class BlackHoleManager
{
public:
    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    void clear();

    std::vector<BlackHole>& getBlackHoles();

    void spawn(float x, float y, BlackHoleType type);

    void moveAll(float offset);

    void spawnRandom();

private:
    std::vector<BlackHole> blackHoles;
};