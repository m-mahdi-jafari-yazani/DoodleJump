#include "Platform/PlatformManager.hpp"

#include <algorithm>

#include "Platform/NormalPlatform.hpp"
#include "Core/Config.hpp"

PlatformManager::PlatformManager()
    : randomEngine(std::random_device{}()),
      xDistribution(
          Config::Platform::MinX,
          Config::Platform::MaxX)
{
    createInitialPlatforms();
}

void PlatformManager::update(float deltaTime)
{
    for (auto& platform : platforms)
    {
        platform->update(deltaTime);
    }

    removeOffScreenPlatforms();

    spawnPlatforms();
}

void PlatformManager::draw(sf::RenderWindow& window) const
{
    for (const auto& platform : platforms)
    {
        platform->draw(window);
    }
}

void PlatformManager::moveAll(float dy)
{
    for (auto& platform : platforms)
    {
        platform->move(0.f, dy);
    }
}

const std::vector<std::unique_ptr<Platform>>&
PlatformManager::getPlatforms() const
{
    return platforms;
}

void PlatformManager::spawnPlatforms()
{
    while (platforms.size() < Config::Platform::Count)
    {
        const float x = xDistribution(randomEngine);

        platforms.push_back(
            platformFactory.createPlatform(
                x,
                Config::Platform::SpawnY
            )
        );
    }
}

void PlatformManager::removeOffScreenPlatforms()
{
    platforms.erase(
        std::remove_if(
            platforms.begin(),
            platforms.end(),
            [](const auto& platform)
            {
                return platform->getPosition().y >
                       Config::Platform::DestroyY;
            }),
        platforms.end());
}

void PlatformManager::reset()
{
    platforms.clear();

    createInitialPlatforms();
}

void PlatformManager::createInitialPlatforms()
{
    platforms.push_back(
        std::make_unique<NormalPlatform>(
            Config::Player::StartX,
            Config::Player::StartY +
            Config::Platform::InitialSupportOffset
        )
    );

    float y = Config::Platform::InitialY;

    for (int i = 0; i < Config::Platform::Count; ++i)
    {
        const float x = xDistribution(randomEngine);

        platforms.push_back(platformFactory.createPlatform(x, y));

        y -= Config::Platform::Spacing;
    }
}


