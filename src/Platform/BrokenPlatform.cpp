#include "Platform/BrokenPlatform.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

BrokenPlatform::BrokenPlatform(float x, float y)
    : Platform(x, y)
{
    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::BrokenPlatform
        )
    );
}

void BrokenPlatform::update(float deltaTime)
{
    if (!broken)
    {
        return;
    }

    velocityY += Config::BrokenPlatform::Gravity * deltaTime;

    move(0.f, velocityY * deltaTime);
}

bool BrokenPlatform::canJumpOn(
    const PhysicsState& physicsState
) const
{
    if (broken)
    {
        return false;
    }

    return Platform::canJumpOn(physicsState);
}

void BrokenPlatform::onPlayerLanded(Player& player)
{
    broken = true;
}

