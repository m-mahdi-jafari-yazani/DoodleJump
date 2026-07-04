#pragma once

#include "Platform/Platform.hpp"

class NormalPlatform : public Platform
{
public:
    NormalPlatform(float x, float y);

    void update(float deltaTime) override;
};


