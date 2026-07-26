#include "Monster/Monster.hpp"

#include "Core/ResourceManager.hpp"
#include "Core/Config.hpp"

Monster::Monster()
    : speed(Config::Monster::Speed),
      direction(1),
      health(Config::Monster::DefaultHealth),
      alive(true)
{
    auto& resources = ResourceManager::getInstance();

    if (std::rand() % 2 == 0)
    {
        sprite.setTexture(
            resources.getTexture(
                Config::Assets::Monsters::MonsterOne
            )
        );
    }
    else
    {
        sprite.setTexture(
            resources.getTexture(
                Config::Assets::Monsters::MonsterTwo
            )
        );
    }
}

void Monster::update(float deltaTime)
{
    sprite.move(
        direction * speed * deltaTime,
        0.f
    );

    const sf::FloatRect bounds =
        sprite.getGlobalBounds();

    if (bounds.left <= 0.f)
    {
        direction = 1;

        sprite.setPosition(
            0.f,
            sprite.getPosition().y
        );
    }

    if (bounds.left + bounds.width >=
        Config::Window::Width)
    {
        direction = -1;

        sprite.setPosition(
            Config::Window::Width -
            bounds.width,
            sprite.getPosition().y
        );
    }
}

void Monster::draw(sf::RenderWindow& window) const
{
    if (alive)
    {
        window.draw(sprite);
    }
}

void Monster::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

sf::Vector2f Monster::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Monster::getBounds() const
{
    return sprite.getGlobalBounds();
}

void Monster::move(float dx, float dy)
{
    sprite.move(dx, dy);
}

void Monster::moveVertical(float dy)
{
    sprite.move(0.f, dy);
}

bool Monster::isAlive() const
{
    return alive;
}

void Monster::kill()
{
    alive = false;
}

void Monster::damage(int amount)
{
    health -= amount;

    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}

int Monster::getHealth() const
{
    return health;
}

void Monster::setHealth(int value)
{
    health = value;
}

void Monster::setTexture(
    const sf::Texture& texture
)
{
    sprite.setTexture(texture);
}

void Monster::setScale(
    float x,
    float y
)
{
    sprite.setScale(x, y);
}

void Monster::setDirection(int value)
{
    direction = value;
}

int Monster::getDirection() const
{
    return direction;
}

bool Monster::canPlayerBounce(
    const PhysicsState& physicsState
) const
{
    if (!alive)
    {
        return false;
    }

    if (physicsState.velocityY <= 0.f)
    {
        return false;
    }

    const sf::FloatRect& previousBounds =
        physicsState.previousBounds;

    const sf::FloatRect& currentBounds =
        physicsState.currentBounds;

    const sf::FloatRect monsterBounds =
        getBounds();

    const bool crossedTop =

        previousBounds.top +
        previousBounds.height
        <=
        monsterBounds.top

        &&

        currentBounds.top +
        currentBounds.height
        >=
        monsterBounds.top;

    const bool overlap =

        currentBounds.left <
        monsterBounds.left +
        monsterBounds.width

        &&

        currentBounds.left +
        currentBounds.width >
        monsterBounds.left;

    return crossedTop && overlap;
}
