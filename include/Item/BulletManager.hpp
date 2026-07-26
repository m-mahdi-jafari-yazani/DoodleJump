#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Item/Bullet.hpp"

class BulletManager
{
public:

    BulletManager();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    void shoot(float x, float y);

    void removeOffScreenBullets();

    void clear();

    std::vector<std::unique_ptr<Bullet>>& getBullets();

    const std::vector<std::unique_ptr<Bullet>>& getBullets() const;

private:

    std::vector<std::unique_ptr<Bullet>> bullets;
};