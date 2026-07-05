#pragma once

#include "Platform.hpp"

class BrokenPlatform : public Platform
{
public:
    BrokenPlatform(float x, float y);

    void update(float deltaTime) override;

    bool canJumpOn(
        const PhysicsState& physicsState
    ) const override;

    void onPlayerLanded(Player& player) override;

    bool canHaveSpring() const override;

private:
    bool broken = false;

    float velocityY = 0.f;
};