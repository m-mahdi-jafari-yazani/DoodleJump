#include "Platform/PlatformEntry.hpp"

#include <cassert>

#include "Player.hpp"
#include "Core/Config.hpp"


PlatformEntry::PlatformEntry(
    std::unique_ptr<Platform> platform,
    std::unique_ptr<Spring> spring
)
    : platform(std::move(platform)),
      spring(std::move(spring))
{
    assert(this->platform);
}

Platform&
PlatformEntry::getPlatform()
{
    assert(platform);

    return *platform;
}

const Platform&
PlatformEntry::getPlatform() const
{
    assert(platform);

    return *platform;
}

Spring&
PlatformEntry::getSpring()
{
    assert(spring);

    return *spring;
}

const Spring&
PlatformEntry::getSpring() const
{
    assert(spring);

    return *spring;
}

bool PlatformEntry::hasSpring() const
{
    return static_cast<bool>(spring);
}

void PlatformEntry::syncSpring()
{
    if (!hasSpring())
    {
        return;
    }

    Spring& spring = getSpring();
    Platform& platform = getPlatform();

    spring.setPosition(
        platform.getPosition().x +
        (platform.getWidth() -
        spring.getBounds().width) / 2.f,

        platform.getPosition().y +
        Config::Spring::OffsetY
    );
}

void PlatformEntry::update(float deltaTime)
{
    getPlatform().update(deltaTime);

    syncSpring();
}

void PlatformEntry::draw(sf::RenderWindow& window) const
{
    platform->draw(window);

    if (hasSpring())
    {
        spring->draw(window);
    }
}

void PlatformEntry::move(float dy)
{
    getPlatform().move(0.f, dy);

    syncSpring();
}

bool PlatformEntry::isOffScreen() const
{
    return platform->getPosition().y >
           Config::Platform::DestroyY;
}

bool PlatformEntry::canPlayerJumpOn(
    const PhysicsState& physicsState
) const
{
    return platform->canJumpOn(physicsState);
}

void PlatformEntry::playerLanded(Player& player)
{
    platform->onPlayerLanded(player);
}

bool PlatformEntry::checkSpringCollision(Player& player)
{
    if (!hasSpring())
    {
        return false;
    }

    Spring& spring = getSpring();

    if (spring.isUsed())
    {
        return false;
    }

    if (!player.getBounds().intersects(
        spring.getBounds()))
    {
        return false;
    }

    spring.use();

    player.springJump();

    return true;
}

