#pragma once

#include <vector>

#include "Player.hpp"
#include "Platform/PlatformEntry.hpp"

class CollisionManager
{
public:
    void handlePlayerPlatforms(
        Player& player,
        std::vector<PlatformEntry>& platformEntries
    );

    void handlePlayerSprings(
        Player& player,
        std::vector<PlatformEntry>& platformEntries
    );
};

