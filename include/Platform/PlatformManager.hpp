#pragma once

#include <memory>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "Platform/PlatformEntry.hpp"
#include "Platform/PlatformEntryFactory.hpp"
#include "Platform/PlatformSpawner.hpp"

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
    std::vector<PlatformEntry> platformEntries;

    PlatformSpawner platformSpawner;
};