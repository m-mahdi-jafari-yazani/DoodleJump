#include "Item/Spring.hpp"

#include "Core/ResourceManager.hpp"
#include "Core/Config.hpp"
#include "Platform/Platform.hpp"

Spring::Spring(float x, float y)
{
    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::Spring
        )
    );

    sprite.setPosition(x, y);
}

void Spring::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

sf::FloatRect Spring::getBounds() const
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Spring::getPosition() const
{
    return sprite.getPosition();
}

void Spring::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

bool Spring::isUsed() const
{
    return used;
}

void Spring::use()
{
    used = true;
}

void Spring::reset()
{
    used = false;
}
