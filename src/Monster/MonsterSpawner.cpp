#include "Monster/MonsterSpawner.hpp"

#include "Core/Config.hpp"

MonsterSpawner::MonsterSpawner()
    :
    randomEngine(std::random_device{}()),
    offsetDistribution(
        Config::Monster::MinOffsetX,
        Config::Monster::MaxOffsetX
    ),
    verticalDistribution(-40.f, 40.f)
{
}

std::unique_ptr<Monster>
MonsterSpawner::create(
    const Platform& platform,
    const std::vector<std::unique_ptr<Monster>>& monsters
)
{
    sf::Vector2f position =
        generatePosition(
            platform,
            monsters
        );

    return monsterFactory.createMonster(
        position.x,
        position.y
    );
}

sf::Vector2f
MonsterSpawner::findSpawnPosition(
    const Platform& platform
)
{
    float x =
        platform.getPosition().x +
        offsetDistribution(randomEngine);

    float y =
        platform.getPosition().y -
        Config::Monster::SpawnAboveDistance +
        verticalDistribution(randomEngine);

    return {x, y};
}

bool MonsterSpawner::isPositionValid(
    const sf::Vector2f& position,
    const std::vector<std::unique_ptr<Monster>>& monsters
) const
{
    for (const auto& monster : monsters)
    {
        if (!monster->isAlive())
        {
            continue;
        }

        float dy =
            std::abs(
                monster->getPosition().y -
                position.y
            );

        if (dy < Config::Monster::MinVerticalDistance)
        {
            return false;
        }
    }

    return true;
}

sf::Vector2f
MonsterSpawner::generatePosition(
    const Platform& platform,
    const std::vector<std::unique_ptr<Monster>>& monsters
)
{
    constexpr int MaxAttempts = 30;

    for (int i = 0; i < MaxAttempts; i++)
    {
        sf::Vector2f position =
            findSpawnPosition(platform);

        if (isPositionValid(position, monsters))
        {
            return position;
        }
    }

    return findSpawnPosition(platform);
}

void MonsterSpawner::setDifficulty(
    Difficulty difficulty
)
{
    monsterFactory.setDifficulty(
        difficulty
    );
}
