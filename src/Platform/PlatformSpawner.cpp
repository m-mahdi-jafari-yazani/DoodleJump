#include "Platform/PlatformSpawner.hpp"

#include "Core/Config.hpp"

PlatformSpawner::PlatformSpawner()
    :
    randomEngine(std::random_device{}()),
    xDistribution(
        Config::Platform::MinX,
        Config::Platform::MaxX
    )
{
}

PlatformEntry PlatformSpawner::create(
    float y,
    const std::vector<PlatformEntry>& entries
)
{
    float x;
    int attempts = 0;

    do
    {
        x = xDistribution(randomEngine);
        ++attempts;
    }
    while (
        attempts < Config::Platform::MaxSpawnAttempts &&
        !isSpawnPositionValid(
            x,
            y,
            entries
        )
    );

    return platformEntryFactory.create(
        x,
        y
    );
}

bool PlatformSpawner::isSpawnPositionValid(
    float x,
    float y,
    const std::vector<PlatformEntry>& entries
) const
{
    for (const auto& entry : entries)
    {
        const auto& platform = entry.getPlatform();

        const float dx = std::abs(platform.getPosition().x - x);
        const float dy = std::abs(platform.getPosition().y - y);

        if (
            dx < Config::Platform::MinHorizontalDistance &&
            dy < Config::Platform::MinVerticalCheckDistance)
        {
            return false;
        }
    }

    return true;
}

