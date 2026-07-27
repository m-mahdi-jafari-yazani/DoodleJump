#include "BlackHole/BlackHoleManager.hpp"

#include <algorithm>

#include "Core/Config.hpp"

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
