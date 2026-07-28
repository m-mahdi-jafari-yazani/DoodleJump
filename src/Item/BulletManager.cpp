#include "Item/BulletManager.hpp"

#include <algorithm>

BulletManager::BulletManager()
{
}

void BulletManager::update(float deltaTime)
{
    for (auto& bullet : bullets)
    {
        bullet->update(deltaTime);
    }

    bullets.erase(
        std::remove_if(
            bullets.begin(),
            bullets.end(),
            [](const auto& bullet)
            {
                return !bullet->isAlive();
            }),
        bullets.end()
    );

    removeOffScreenBullets();
}

void BulletManager::draw(sf::RenderWindow& window) const
{
    for (const auto& bullet : bullets)
    {
        bullet->draw(window);
    }
}

void BulletManager::shoot(
    float x,
    float y
)
{
    bullets.push_back(
        std::make_unique<Bullet>(
            x,
            y
        )
    );
}

void BulletManager::removeOffScreenBullets()
{
    bullets.erase(
        std::remove_if(
            bullets.begin(),
            bullets.end(),
            [](const auto& bullet)
            {
                return bullet->isOffScreen();
            }),
        bullets.end()
    );
}

void BulletManager::clear()
{
    bullets.clear();
}


std::vector<std::unique_ptr<Bullet>>&
BulletManager::getBullets()
{
    return bullets;
}

const std::vector<std::unique_ptr<Bullet>>&
BulletManager::getBullets() const
{
    return bullets;
}
