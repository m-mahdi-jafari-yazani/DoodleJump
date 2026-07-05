#include "CollisionManager.hpp"

#include "Physics/PhysicsState.hpp"

void CollisionManager::handlePlayerPlatforms(
    Player& player,
    std::vector<PlatformEntry>& platformEntries
)
{
    const PhysicsState physicsState =
        player.getPhysicsState();

    for (auto& entry : platformEntries)
    {
        if (entry.canPlayerJumpOn(physicsState))
        {
            entry.playerLanded(player);
            break;
        }
    }
}

void CollisionManager::handlePlayerSprings(
    Player& player,
    std::vector<PlatformEntry>& platformEntries
)
{
    if (!player.isFalling())
    {
        return;
    }

    for (auto& entry : platformEntries)
    {
        if (entry.checkSpringCollision(player))
        {
            break;
        }
    }
}

