#pragma once

#include <memory>
#include <vector>

#include "Player.hpp"
#include "Platform/Platform.hpp"

class CollisionManager
{
public:
    void handlePlayerPlatforms(
        Player& player,
        const std::vector<std::unique_ptr<Platform>>& platforms
    ) const;
};
