#pragma once

#include <memory>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "Platform/PlatformEntry.hpp"
#include "Platform/PlatformEntryFactory.hpp"

class PlatformManager
{
public:
    PlatformManager();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    std::vector<PlatformEntry>& getPlatformEntries();
    const std::vector<PlatformEntry>& getPlatformEntries() const;

    void moveAll(float dy);

    void spawnPlatforms();

    void removeOffScreenPlatforms();

    void reset();    

private:
    void createInitialPlatforms();

private:
    PlatformEntryFactory platformEntryFactory;

    std::vector<PlatformEntry> platformEntries;

    std::mt19937 randomEngine;
    std::uniform_real_distribution<float> xDistribution;
};