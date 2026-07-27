#include "Player.hpp"

#include <stdexcept>

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

Player::Player()
{
    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::RightDoodle
        )
    );

    const sf::Texture* texture = sprite.getTexture();

    sprite.setOrigin(
        texture->getSize().x / 2.f,
        texture->getSize().y / 2.f
    );

    sprite.setPosition(
        Config::Player::StartX,
        Config::Player::StartY
    );
}

void Player::update(float deltaTime, float windowWidth)
{
    previousBounds = sprite.getGlobalBounds();

    bool movingLeft =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A);

    bool movingRight =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    updateDirection(movingLeft, movingRight);

    if (isShooting &&
        shootingClock.getElapsedTime().asMilliseconds() >= 120)
    {
        isShooting = false;

        if (movingLeft)
        {
            sprite.setTexture(
                ResourceManager::getInstance().getTexture(
                    Config::Assets::LeftDoodle
                )
            );
        }
        else
        {
            sprite.setTexture(
                ResourceManager::getInstance().getTexture(
                    Config::Assets::RightDoodle
                )
            );
        }
    }

    if (movingLeft)
    {
        sprite.move(-Config::Player::MoveSpeed * deltaTime, 0.f);
    }

    if (movingRight)
    {
        sprite.move(Config::Player::MoveSpeed  * deltaTime, 0.f);
    }

    // Gravity
    velocityY += Config::Player::Gravity * deltaTime;
    sprite.move(0.f, velocityY * deltaTime);

    // Wrap Around
    if (sprite.getPosition().x < 0.f)
    {
        sprite.setPosition(windowWidth, sprite.getPosition().y);
    }
    else if (sprite.getPosition().x > windowWidth)
    {
        sprite.setPosition(0.f, sprite.getPosition().y);
    }
}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}
void Player::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

sf::FloatRect Player::getBounds() const
{
    sf::FloatRect bounds =
        sprite.getGlobalBounds();

    bounds.left += bounds.width * 0.15f;
    bounds.top += bounds.height * 0.10f;

    bounds.width *= 0.70f;
    bounds.height *= 0.80f;

    return bounds;
}

void Player::move(float dx, float dy)
{
    sprite.move(dx, dy);
}

void Player::jump(float jumpForce)
{
    velocityY = -jumpForce;
}

void Player::springJump()
{
    velocityY = Config::Spring::JumpVelocity;
}

float Player::getVelocityY() const
{
    return velocityY;
}
void Player::setVelocityY(float velocity)
{
    velocityY = velocity;
}

PhysicsState Player::getPhysicsState() const
{
    return {
        previousBounds,
        sprite.getGlobalBounds(),
        velocityY
    };
}

void Player::reset()
{
    sprite.setPosition(
        Config::Player::StartX,
        Config::Player::StartY
    );

    velocityY = 0.f;

    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::RightDoodle
        )
    );
}

bool Player::isFalling() const
{
    return velocityY > 0.f;
}

void Player::updateDirection(bool movingLeft, bool movingRight)
{
    if (isShooting)
    {
        return;
    }

    if (movingLeft)
    {
        sprite.setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::LeftDoodle
            )
        );
    }
    else if (movingRight)
    {
        sprite.setTexture(
            ResourceManager::getInstance().getTexture(
                Config::Assets::RightDoodle
            )
        );
    }
}

sf::Vector2f Player::getGunPosition() const
{
    sf::FloatRect bounds =
        sprite.getGlobalBounds();

    return
    {
        bounds.left + bounds.width / 2.f,
        bounds.top
    };
}

void Player::startShooting()
{
    isShooting = true;
    shootingClock.restart();

    sprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::ShootingDoodle
        )
    );

    const sf::Texture* texture = sprite.getTexture();

    sprite.setOrigin(
        texture->getSize().x / 2.f,
        texture->getSize().y / 2.f
    );
}
