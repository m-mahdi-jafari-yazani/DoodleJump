#include "Platform/NormalPlatform.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

NormalPlatform::NormalPlatform(float x, float y)
    : Platform(x, y)
{
    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::NormalPlatform
        )
    );
}

void NormalPlatform::update(float deltaTime)
{
    // normal platform has not move
}

