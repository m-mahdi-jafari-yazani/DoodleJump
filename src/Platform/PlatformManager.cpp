#include "Platform/PlatformManager.hpp"

#include <algorithm>

#include "Platform/NormalPlatform.hpp"
#include "Core/Config.hpp"

PlatformManager::PlatformManager()
{
    createInitialPlatforms();
}

void PlatformManager::update(float deltaTime)
{
    for (auto& entry : platformEntries)
    {   
        entry.update(deltaTime);
    }

    removeOffScreenPlatforms();

    spawnPlatforms();
}

void PlatformManager::draw(sf::RenderWindow& window) const
{
    for (const auto& entry : platformEntries)
    {
        entry.draw(window);
    }
}

std::vector<PlatformEntry>&
PlatformManager::getPlatformEntries()
{
    return platformEntries;
}

const std::vector<PlatformEntry>&
PlatformManager::getPlatformEntries() const
{
    return platformEntries;
}

void PlatformManager::moveAll(float dy)
{
    for (auto& entry : platformEntries)
    {
        entry.move(dy);
    }
}

void PlatformManager::spawnPlatforms()
{
    while (platformEntries.size() < Config::Platform::Count)
    {
        platformEntries.push_back(
            platformSpawner.create(
                Config::Platform::SpawnY,
                platformEntries
            )
        );
    }
}

void PlatformManager::removeOffScreenPlatforms()
{
    platformEntries.erase(
        std::remove_if(
            platformEntries.begin(),
            platformEntries.end(),
            [](const PlatformEntry& entry)
            {
                return entry.isOffScreen();
            }),
        platformEntries.end()
    );
}

void PlatformManager::reset()
{
    platformEntries.clear();

    createInitialPlatforms();
}

void PlatformManager::createInitialPlatforms()
{
    platformEntries.clear();

    PlatformEntry firstEntry(
        std::make_unique<NormalPlatform>(
            Config::Player::StartX,
            Config::Player::StartY +
            Config::Platform::InitialSupportOffset
        )
    );

    platformEntries.push_back(std::move(firstEntry));

    float y = Config::Platform::InitialY;

    for (int i = 0; i < Config::Platform::Count; ++i)
    {
        platformEntries.push_back(
            platformSpawner.create(
                y,
                platformEntries
            )
        );

        y -= Config::Platform::Spacing;
    }
}




