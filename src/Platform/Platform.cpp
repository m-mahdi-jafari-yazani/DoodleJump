#include "Platform/Platform.hpp"
#include "Player.hpp"
#include "Core/Config.hpp"

Platform::Platform(float x, float y)
{
    sprite.setPosition(x, y);
}

void Platform::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void Platform::move(float dx, float dy)
{
    sprite.move(dx, dy);
}

bool Platform::canJumpOn(const PhysicsState& physicsState) const
{
    if (physicsState.velocityY <= 0.f)
    {
        return false;
    }

    const sf::FloatRect& previousBounds = physicsState.previousBounds;
    const sf::FloatRect& currentBounds = physicsState.currentBounds;
    const sf::FloatRect platformBounds = getBounds();

    const bool crossedPlatform =
        previousBounds.top + previousBounds.height <= platformBounds.top &&
        currentBounds.top + currentBounds.height >= platformBounds.top;

    const bool horizontalOverlap =
        currentBounds.left < platformBounds.left + platformBounds.width &&
        currentBounds.left + currentBounds.width > platformBounds.left;

    return crossedPlatform && horizontalOverlap;
}

void Platform::onPlayerLanded(Player& player)
{
    player.jump(Config::Player::JumpForce);
}

sf::FloatRect Platform::getBounds() const
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Platform::getPosition() const
{
    return sprite.getPosition();
}

void Platform::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

float Platform::getTop() const
{
    return sprite.getGlobalBounds().top;
}

float Platform::getWidth() const
{
    return sprite.getGlobalBounds().width;
}

bool Platform::canHaveSpring() const
{
    return true;
}

