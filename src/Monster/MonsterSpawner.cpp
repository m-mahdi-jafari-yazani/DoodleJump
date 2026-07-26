#include "Monster/MonsterSpawner.hpp"

#include "Core/Config.hpp"

MonsterSpawner::MonsterSpawner()
    :
    randomEngine(std::random_device{}()),
    offsetDistribution(
        Config::Monster::MinOffsetX,
        Config::Monster::MaxOffsetX
    )
{
}

std::unique_ptr<Monster>
MonsterSpawner::create(
    const Platform& platform
)
{
    sf::Vector2f position =
        findSpawnPosition(platform);

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
        Config::Monster::SpawnAboveDistance;

    return {x, y};
}