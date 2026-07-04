#include "Camera.hpp"

#include "Core/Config.hpp"

float Camera::update(Player& player)
{
    if (player.getPosition().y > Config::Camera::ThresholdY)
    {
        return 0.f;
    }

    const float offset =
        Config::Camera::ThresholdY - player.getPosition().y;

    player.move(0.f, offset);

    return offset;
}

