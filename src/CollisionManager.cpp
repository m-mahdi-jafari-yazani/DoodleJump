#include "CollisionManager.hpp"

#include "Physics/PhysicsState.hpp"

void CollisionManager::handlePlayerPlatforms(
    Player& player,
    const std::vector<std::unique_ptr<Platform>>& platforms
) const
{
    const PhysicsState physicsState = player.getPhysicsState();

    for (const auto& platform : platforms)
    {
        if (platform->canJumpOn(physicsState))
        {
            platform->onPlayerLanded(player);
            break;
        }
    }
}