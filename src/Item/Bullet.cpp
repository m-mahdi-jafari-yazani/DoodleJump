#include "Item/Bullet.hpp"

#include "Core/Config.hpp"

Bullet::Bullet(float x, float y)
{
    speed = Config::Bullet::Speed;

    shape.setRadius(
        Config::Bullet::Radius
    );

    shape.setFillColor(
        Config::Bullet::BulletColor
    );

    shape.setOrigin(
        Config::Bullet::Radius,
        Config::Bullet::Radius
    );

    shape.setPosition(x, y);
}

void Bullet::update(float deltaTime)
{
    shape.move(
        0.f,
        -speed * deltaTime
    );
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

bool Bullet::isOffScreen() const
{
    return
        shape.getPosition().y <
        -Config::Bullet::Radius * 2.f;
}

sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}

bool Bullet::isAlive() const
{
    return alive;
}

void Bullet::destroy()
{
    alive = false;
}
