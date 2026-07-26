#include "Monster/MonsterFactory.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

MonsterFactory::MonsterFactory()
    :
    randomEngine(std::random_device{}()),
    typeDistribution(0,1)
{
}

MonsterType MonsterFactory::chooseMonsterType()
{
    if (typeDistribution(randomEngine) == 0)
    {
        return MonsterType::TypeOne;
    }

    return MonsterType::TypeTwo;
}

std::unique_ptr<Monster>
MonsterFactory::createMonster(
    float x,
    float y
)
{
    std::uniform_int_distribution<int> directionDistribution(0, 1);

    auto monster =
        std::make_unique<Monster>();

    MonsterType type =
        chooseMonsterType();

    if (type == MonsterType::TypeOne)
    {
        monster->setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::Monsters::MonsterOne
            )
        );
    }
    else
    {
        monster->setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::Monsters::MonsterTwo
            )
        );
    }

    monster->setScale(0.7f, 0.7f);

    monster->setPosition(x, y);

    monster->setDirection(directionDistribution(randomEngine) == 0 ? -1 : 1);

    return monster;
}
