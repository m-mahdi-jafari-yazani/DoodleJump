#include "BlackHole/BlackHoleManager.hpp"

void BlackHoleManager::update(float deltaTime)
{
    for (auto& blackHole : blackHoles)
    {
        blackHole.update(deltaTime);
    }
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