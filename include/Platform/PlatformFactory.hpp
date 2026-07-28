#pragma once

#include <memory>
#include <random>

#include "Platform/Platform.hpp"
#include "Platform/PlatformType.hpp"
#include "Core/Difficulty.hpp"

class PlatformFactory
{
public:
    std::unique_ptr<Platform> createPlatform(float x, float y);

    void setDifficulty(Difficulty difficulty);

private:
    PlatformType choosePlatformType();

    std::unique_ptr<Platform> createPlatform(PlatformType type, float x, float y);

private:
    std::mt19937 randomEngine{std::random_device{}()};

    std::uniform_int_distribution<int> chanceDistribution{1, 100};
    
    Difficulty difficulty = Difficulty::Medium;
};
