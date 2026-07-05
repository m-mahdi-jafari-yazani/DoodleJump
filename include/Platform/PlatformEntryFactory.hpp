#pragma once

#include <random>

#include "Platform/PlatformEntry.hpp"
#include "Platform/PlatformFactory.hpp"

class PlatformEntryFactory
{
public:
    PlatformEntryFactory();

    PlatformEntry create(float x, float y);

private:
    PlatformFactory platformFactory;

    std::mt19937 randomEngine;

    std::uniform_int_distribution<int> springDistribution;
};
