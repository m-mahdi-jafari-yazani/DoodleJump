#include "Platform/MovingPlatform.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

MovingPlatform::MovingPlatform(float x, float y)
    : Platform(x, y),
      speed(Config::MovingPlatform::Speed),
      direction(1)
{
    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::MovingPlatform
        )
    );
}

void MovingPlatform::update(float deltaTime)
{
    move(speed * direction * deltaTime, 0.f);

    if (getPosition().x <= getWidth() / 2.f)
    {
        direction = 1;
    }
    else if (getPosition().x >=
             Config::Window::Width - getWidth() / 2.f)
    {
        direction = -1;
    }
}

