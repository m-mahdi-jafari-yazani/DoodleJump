#include "Platform/PlatformEntryFactory.hpp"

#include "Core/Config.hpp"

PlatformEntryFactory::PlatformEntryFactory()
    :
    randomEngine(std::random_device{}()),
    springDistribution(0, 99)
{
}

PlatformEntry PlatformEntryFactory::create(float x, float y)
{
    auto platform =
        platformFactory.createPlatform(x, y);

    std::unique_ptr<Spring> spring = nullptr;

    if (platform->canHaveSpring())
    {
        if (springDistribution(randomEngine)
            < Config::Spring::SpawnChance)
        {
            spring =
                std::make_unique<Spring>(
                    platform->getPosition().x,
                    platform->getPosition().y +
                    Config::Spring::OffsetY
                );
        }
    }

    return PlatformEntry(
        std::move(platform),
        std::move(spring)
    );
}
