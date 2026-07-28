#pragma once

#include <memory>
#include <random>
#include <vector>

#include <SFML/System/Vector2.hpp>

#include "Monster/MonsterFactory.hpp"
#include "Platform/PlatformEntry.hpp"
#include "Core/Difficulty.hpp"

class MonsterSpawner
{
public:
    MonsterSpawner();

    std::unique_ptr<Monster> create(
        const Platform& platform,
        const std::vector<std::unique_ptr<Monster>>& monsters
    );

    sf::Vector2f findSpawnPosition(
        const Platform& platform
    );

    void setDifficulty(Difficulty difficulty);
private:
    bool isPositionValid(
        const sf::Vector2f& position,
        const std::vector<std::unique_ptr<Monster>>& monsters
    ) const;

    sf::Vector2f generatePosition(
        const Platform& platform,
        const std::vector<std::unique_ptr<Monster>>& monsters
    );

private:
    MonsterFactory monsterFactory;

    std::mt19937 randomEngine;

    std::uniform_real_distribution<float> offsetDistribution;

    std::uniform_real_distribution<float> verticalDistribution;
};