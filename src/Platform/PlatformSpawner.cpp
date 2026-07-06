#include "Platform/PlatformSpawner.hpp"

#include <cmath>

#include "Core/Config.hpp"

PlatformSpawner::PlatformSpawner()
:
randomEngine(std::random_device{}()),
xDistribution(
    Config::Platform::MinX,
    Config::Platform::MaxX
),
verticalSpacingDistribution(
    Config::Platform::MinVerticalSpacing,
    Config::Platform::MaxVerticalSpacing
)
{
}

PlatformEntry PlatformSpawner::create(
    const std::vector<PlatformEntry>& entries
)
{
    sf::Vector2f position =
        findSpawnPosition(entries);

    return platformEntryFactory.create(
        position.x,
        position.y
    );
}

float PlatformSpawner::generateSpawnX()
{
    return xDistribution(randomEngine);
}

float PlatformSpawner::calculateSpawnY(
    const std::vector<PlatformEntry>& entries
)
{
    if (entries.empty())
    {
        return Config::Platform::InitialY;
    }

    const Platform& lastPlatform =
        entries.back().getPlatform();

    float spacing =
        verticalSpacingDistribution(
            randomEngine
        );

    return
        lastPlatform.getPosition().y
        - spacing;
}

bool PlatformSpawner::isSpawnPositionValid(
    float x,
    float y,
    const std::vector<PlatformEntry>& entries
) const
{
    for (const auto& entry : entries)
    {
        if (isTooClose(entry.getPlatform(), x, y))
        {
            return false;
        }
    }
    return true;
}

sf::Vector2f PlatformSpawner::findSpawnPosition(const std::vector<PlatformEntry>& entries)
{
    float y = calculateSpawnY(entries);
    float x;

    int attempts = 0;

    do
    {
        x = generateSpawnX();
        ++attempts;

    } while (
        attempts < Config::Platform::MaxSpawnAttempts &&
        !isSpawnPositionValid(x, y, entries)
    );

    return {x, y};
}

bool PlatformSpawner::isTooClose(
    const Platform& platform,
    float x,
    float y
) const
{
    const float dx =
        std::abs(platform.getPosition().x - x);

    const float dy =
        std::abs(platform.getPosition().y - y);

    return
        dx < Config::Platform::MinHorizontalDistance &&
        dy < Config::Platform::MinVerticalCheckDistance;
}

