#pragma once

#include <random>

#include "Platform/PlatformEntryFactory.hpp"

class PlatformSpawner
{
public:
    PlatformSpawner();

    PlatformEntry create(
        float y,
        const std::vector<PlatformEntry>& entries
    );

private:
    bool isSpawnPositionValid(
        float x,
        float y,
        const std::vector<PlatformEntry>& entries
    ) const;

private:
    std::mt19937 randomEngine;

    std::uniform_real_distribution<float> xDistribution;

    PlatformEntryFactory platformEntryFactory;
};
