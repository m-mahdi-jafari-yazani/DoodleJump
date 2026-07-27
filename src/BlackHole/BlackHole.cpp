#include "BlackHole/BlackHole.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

BlackHole::BlackHole(
    BlackHoleType type,
    float x,
    float y
)
    : type(type)
{
    if (type == BlackHoleType::Small)
    {
        sprite.setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::SmallBlackHole
            )
        );
    }
    else
    {
        sprite.setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::LargeBlackHole
            )
        );
    }

    const sf::Texture* texture =
        sprite.getTexture();

    sprite.setOrigin(
        texture->getSize().x / 2.f,
        texture->getSize().y / 2.f
    );

    sprite.setPosition(x, y);
}

void BlackHole::draw(
    sf::RenderWindow& window
) const
{
    window.draw(sprite);
}

void BlackHole::update(float)
{
}

sf::FloatRect BlackHole::getBounds() const
{
    sf::FloatRect bounds =
        sprite.getGlobalBounds();

    bounds.left += bounds.width * 0.20f;
    bounds.top += bounds.height * 0.20f;

    bounds.width *= 0.60f;
    bounds.height *= 0.60f;

    return bounds;
}

float BlackHole::getY() const
{
    return sprite.getPosition().y;
}

void BlackHole::move(float offset)
{
    sprite.move(0.f, offset);
}
