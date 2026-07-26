#pragma once

#include "Platform.hpp"

class MovingPlatform : public Platform
{
public:
    MovingPlatform(float x, float y);

    void update(float deltaTime) override;

    PlatformType getType() const override;

private:
    float speed;
    int direction;
};