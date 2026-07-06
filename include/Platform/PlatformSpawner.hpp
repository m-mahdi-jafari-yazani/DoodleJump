#pragma once

#include <random>

#include "Platform/PlatformEntryFactory.hpp"

class PlatformSpawner
{
public:
    PlatformSpawner();

    PlatformEntry create(const std::vector<PlatformEntry>& entries);

    float generateSpawnX();

    float calculateSpawnY(const std::vector<PlatformEntry>& entries);

private:
    bool isSpawnPositionValid(
        float x,
        float y,
        const std::vector<PlatformEntry>& entries
    ) const;

    sf::Vector2f findSpawnPosition(
        const std::vector<PlatformEntry>& entries
    );

    bool isTooClose(
        const Platform& platform,
        float x,
        float y
    ) const;

private:
    std::mt19937 randomEngine;

    std::uniform_real_distribution<float> xDistribution;

    PlatformEntryFactory platformEntryFactory;

    std::uniform_real_distribution<float> verticalSpacingDistribution;
};
