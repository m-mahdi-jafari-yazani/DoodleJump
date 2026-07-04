#pragma once

#include "Player.hpp"
#include "Platform/PlatformManager.hpp"

class Camera
{
public:
    float update(Player& player);

    void reset();
};