#pragma once

#include <memory>
#include <random>
#include <vector>

#include <SFML/System/Vector2.hpp>

#include "Monster/MonsterFactory.hpp"
#include "Platform/PlatformEntry.hpp"

class MonsterSpawner
{
public:
    MonsterSpawner();

    std::unique_ptr<Monster> create(
        const Platform& platform
    );

private:
    sf::Vector2f findSpawnPosition(
        const Platform& platform
    );

private:
    MonsterFactory monsterFactory;

    std::mt19937 randomEngine;

    std::uniform_real_distribution<float> offsetDistribution;
};