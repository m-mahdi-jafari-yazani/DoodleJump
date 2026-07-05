#include "Platform/PlatformManager.hpp"

#include <algorithm>

#include "Platform/NormalPlatform.hpp"
#include "Core/Config.hpp"

PlatformManager::PlatformManager()
    :
    randomEngine(std::random_device{}()),
    xDistribution(
        Config::Platform::MinX,
        Config::Platform::MaxX
    )
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
        const float x =
            xDistribution(randomEngine);

        PlatformEntry entry = platformEntryFactory.create(x, Config::Platform::SpawnY);

        platformEntries.push_back(
            std::move(entry)
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
        const float x = xDistribution(randomEngine);

        PlatformEntry entry = platformEntryFactory.create(x, y);

        platformEntries.push_back(std::move(entry));

        y -= Config::Platform::Spacing;
    }
}




