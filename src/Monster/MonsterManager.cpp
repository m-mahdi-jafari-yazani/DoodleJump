#include "Monster/MonsterManager.hpp"

#include <algorithm>
#include <cmath>
#include <unordered_set>

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

    std::uniform_int_distribution<std::size_t>
    platformDistribution(
        0,
        platforms.size() - 1
    );

    std::vector<const Platform*> spawnPlatforms;

    std::vector<float> usedHeights;

    for (const auto& entry : platforms)
    {
        const Platform& platform =
            entry.getPlatform();

        if (platform.getPosition().y < -50.f)
        {
            spawnPlatforms.push_back(&platform);
        }
    }

    if (spawnPlatforms.empty())
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

        std::uniform_int_distribution<std::size_t>
            distribution(
            0,
            spawnPlatforms.size() - 1
        );

        const Platform& platform =
            *spawnPlatforms[
                distribution(randomEngine)
            ];

        

        auto monster =
            monsterSpawner.create(
            platform,
            monsters
        );

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

