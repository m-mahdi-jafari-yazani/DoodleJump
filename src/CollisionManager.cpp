#include "CollisionManager.hpp"

#include "Physics/PhysicsState.hpp"

void CollisionManager::handlePlayerPlatforms(
    Player& player,
    std::vector<PlatformEntry>& platformEntries,
    AudioManager& audio
)
{
    const PhysicsState physicsState =
        player.getPhysicsState();

    for (auto& entry : platformEntries)
    {
        if (entry.canPlayerJumpOn(physicsState))
        {
            entry.playerLanded(player);

            audio.play("jump");

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

