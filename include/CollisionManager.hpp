#pragma once

#include <vector>

#include "Player.hpp"
#include "Platform/PlatformEntry.hpp"
#include "Core/AudioManager.hpp"

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
};

