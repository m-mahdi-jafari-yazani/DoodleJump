#include "Platform/PlatformFactory.hpp"

#include "Platform/BrokenPlatform.hpp"
#include "Platform/MovingPlatform.hpp"
#include "Platform/NormalPlatform.hpp"

#include "Core/Config.hpp"

std::unique_ptr<Platform> PlatformFactory::createPlatform(float x, float y)
{
    PlatformType type =
        choosePlatformType();

    return createPlatform(type, x, y);
}

PlatformType PlatformFactory::choosePlatformType()
{
    int chance = chanceDistribution(randomEngine);

    if (chance <=
        Config::BrokenPlatform::SpawnChance)
    {
        return PlatformType::Broken;
    }

    chance -=
        Config::BrokenPlatform::SpawnChance;

    if (chance <=
        Config::MovingPlatform::SpawnChance)
    {
        return PlatformType::Moving;
    }

    return PlatformType::Normal;
}

std::unique_ptr<Platform>
PlatformFactory::createPlatform(
    PlatformType type,
    float x,
    float y
)
{
    switch (type)
    {
        case PlatformType::Normal:
            return std::make_unique<NormalPlatform>(
                x,
                y
            );

        case PlatformType::Moving:
            return std::make_unique<MovingPlatform>(
                x,
                y
            );

        case PlatformType::Broken:
            return std::make_unique<BrokenPlatform>(
                x,
                y
            );
    }

    return nullptr;
}

