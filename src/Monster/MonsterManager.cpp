#include "Monster/MonsterManager.hpp"

#include <algorithm>

#include "Core/Config.hpp"

MonsterManager::MonsterManager()
{
}

void MonsterManager::update(float deltaTime)
{
    for (auto& monster : monsters)
    {
        monster->update(deltaTime);
    }

    removeOffScreenMonsters();
}

void MonsterManager::draw(sf::RenderWindow& window) const
{
    for (const auto& monster : monsters)
    {
        monster->draw(window);
    }
}

void MonsterManager::moveAll(float dy)
{
    for (auto& monster : monsters)
    {
        monster->moveVertical(dy);
    }
}

void MonsterManager::addMonster(
    std::unique_ptr<Monster> monster
)
{
    monsters.push_back(std::move(monster));
}

void MonsterManager::removeDeadMonsters()
{
    monsters.erase(

        std::remove_if(

            monsters.begin(),

            monsters.end(),

            [](const auto& monster)
            {
                return !monster->isAlive();
            }),

        monsters.end()
    );
}

void MonsterManager::clear()
{
    monsters.clear();
}

std::vector<std::unique_ptr<Monster>>&
MonsterManager::getMonsters()
{
    return monsters;
}

const std::vector<std::unique_ptr<Monster>>&
MonsterManager::getMonsters() const
{
    return monsters;
}

void MonsterManager::spawnMonsters(
    const std::vector<PlatformEntry>& platforms
)
{
    std::uniform_int_distribution<int> chanceDistribution(
        1,
        100
    );

    static std::mt19937 randomEngine(
        std::random_device{}()
    );

    const Platform* topPlatform = nullptr;

    for (const auto& entry : platforms)
    {
        if (topPlatform == nullptr ||
            entry.getPlatform().getPosition().y <
            topPlatform->getPosition().y)
        {
            topPlatform = &entry.getPlatform();
        }
    }

    if (topPlatform == nullptr)
    {
        return;
    }

    while (monsters.size() < Config::Monster::Count)
    {
        std::uniform_int_distribution<int> chanceDistribution(1, 100);

        static std::mt19937 randomEngine(
            std::random_device{}()
        );

        if (chanceDistribution(randomEngine) >
            Config::Monster::SpawnChance)
        {
            break;
        }

        auto monster =
            monsterSpawner.create(*topPlatform);

        addMonster(std::move(monster));
    }

}

void MonsterManager::removeOffScreenMonsters()
{
    monsters.erase(
        std::remove_if(
            monsters.begin(),
            monsters.end(),
            [](const auto& monster)
            {
                return
                    !monster->isAlive() ||
                    monster->getPosition().y >
                        Config::Window::Height;
            }),
        monsters.end()
    );
}

void MonsterManager::respawnMonsters(
    const std::vector<PlatformEntry>& platforms
)
{
    spawnMonsters(platforms);
}

