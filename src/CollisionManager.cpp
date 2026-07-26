#include "CollisionManager.hpp"

#include "Physics/PhysicsState.hpp"
#include "Core/Config.hpp"

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

bool CollisionManager::handlePlayerMonsters(
    Player& player,
    std::vector<std::unique_ptr<Monster>>& monsters
)
{
    const PhysicsState physicsState =
        player.getPhysicsState();

    for (auto& monster : monsters)
    {
        if (!monster->isAlive())
        {
            continue;
        }

        if (!player.getBounds().intersects(
                monster->getBounds()))
        {
            continue;
        }

        const sf::FloatRect& previous =
            physicsState.previousBounds;

        const sf::FloatRect& current =
            physicsState.currentBounds;

        const sf::FloatRect monsterBounds =
            monster->getBounds();

        const bool landedOnTop =
            physicsState.velocityY > 0.f &&
            previous.top + previous.height <= monsterBounds.top &&
            current.top + current.height >= monsterBounds.top;

        if (landedOnTop)
        {
            player.jump(
                Config::Monster::JumpForce
            );

            monster->kill();

            return false;
        }

        return true;
    }

    return false;
}

void CollisionManager::handleBulletMonsters(
    std::vector<std::unique_ptr<Bullet>>& bullets,
    std::vector<std::unique_ptr<Monster>>& monsters
)
{
    for (auto& bullet : bullets)
    {
        for (auto& monster : monsters)
        {
            if (!monster->isAlive())
            {
                continue;
            }

            if (!bullet->getBounds().intersects(
                    monster->getBounds()))
            {
                continue;
            }

            monster->damage(1);

            break;
        }
    }
}

