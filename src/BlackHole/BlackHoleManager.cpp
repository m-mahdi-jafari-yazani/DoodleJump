#include "BlackHole/BlackHoleManager.hpp"

#include <algorithm>
#include <random>

#include "Core/Config.hpp"

namespace
{
    std::mt19937 generator(
        std::random_device{}()
    );
}

void BlackHoleManager::update(float deltaTime)
{
    for (auto& blackHole : blackHoles)
    {
        blackHole.update(deltaTime);
    }

    blackHoles.erase(
        std::remove_if(
            blackHoles.begin(),
            blackHoles.end(),
            [](const BlackHole& blackHole)
            {
                return
                    blackHole.getY() >
                    Config::BlackHole::DestroyY;
            }
        ),
        blackHoles.end()
    );

    spawnRandom();
}

void BlackHoleManager::draw(
    sf::RenderWindow& window
) const
{
    for (const auto& blackHole : blackHoles)
    {
        blackHole.draw(window);
    }
}

void BlackHoleManager::clear()
{
    blackHoles.clear();
}

std::vector<BlackHole>&
BlackHoleManager::getBlackHoles()
{
    return blackHoles;
}

void BlackHoleManager::spawn(
    float x,
    float y,
    BlackHoleType type
)
{
    blackHoles.emplace_back(
        type,
        x,
        y
    );
}

void BlackHoleManager::moveAll(
    float offset
)
{
    for (auto& blackHole : blackHoles)
    {
        blackHole.move(offset);
    }
}

void BlackHoleManager::spawnRandom()
{
    if (blackHoles.size() >=
        Config::BlackHole::MaxCount)
    {
        return;
    }

    std::uniform_real_distribution<float>
        xDistribution(
            80.f,
            720.f
        );

    std::uniform_real_distribution<float>
        yDistribution(
            -900.f,
            -100.f
        );

    std::uniform_int_distribution<int>
        typeDistribution(
            0,
            1
        );

    BlackHoleType type =
        typeDistribution(generator) == 0 ?
        BlackHoleType::Small :
        BlackHoleType::Large;

    spawn(
        xDistribution(generator),
        yDistribution(generator),
        type
    );
}

