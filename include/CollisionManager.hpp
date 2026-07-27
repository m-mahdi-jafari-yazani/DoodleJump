#pragma once

#include <vector>

#include "Player.hpp"
#include "Platform/PlatformEntry.hpp"
#include "Core/AudioManager.hpp"
#include "Monster/Monster.hpp"
#include "Item/Bullet.hpp"
#include "BlackHole/BlackHole.hpp"

class CollisionManager
{
public:
    void handlePlayerPlatforms(
        Player& player,
        std::vector<PlatformEntry>& platformEntries,
        AudioManager& audio
    );

    void handlePlayerSprings(
        Player& player,
        std::vector<PlatformEntry>& platformEntries
    );

    bool handlePlayerMonsters(
        Player& player,
        std::vector<std::unique_ptr<Monster>>& monsters
    );

    void handleBulletMonsters(
        std::vector<std::unique_ptr<Bullet>>& bullets,
        std::vector<std::unique_ptr<Monster>>& monsters
    );

    bool handlePlayerBlackHoles(
        const Player& player,
        const std::vector<BlackHole>& blackHoles
    ) const;
};


