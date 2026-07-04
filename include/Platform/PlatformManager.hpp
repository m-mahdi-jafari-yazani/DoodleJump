#pragma once

#include <memory>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "Platform.hpp"
#include "Platform/PlatformFactory.hpp"

class PlatformManager
{
public:
    PlatformManager();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    void moveAll(float dy);

    const std::vector<std::unique_ptr<Platform>>& getPlatforms() const;

    void spawnPlatforms();

    void removeOffScreenPlatforms();

    void reset();
    
private:
    void createInitialPlatforms();

private:
    std::vector<std::unique_ptr<Platform>> platforms;
    
    std::mt19937 randomEngine;
    std::uniform_real_distribution<float> xDistribution;

    PlatformFactory platformFactory;
};