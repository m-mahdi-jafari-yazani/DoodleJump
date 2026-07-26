#pragma once

#include <SFML/Graphics.hpp>

#include "Physics/PhysicsState.hpp"

class Player
{
public:
    Player();

    void update(float deltaTime, float windowWidth);
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    sf::FloatRect getBounds() const;

    void move(float dx, float dy);

    void jump(float jumpForce);
    void springJump();

    float getVelocityY() const;
    void setVelocityY(float velocity);

    PhysicsState getPhysicsState() const;

    void reset();

    bool isFalling() const;

    sf::Vector2f getGunPosition() const;

    void startShooting();

private:
    void updateDirection(bool movingLeft, bool movingRight);

private:
    sf::Sprite sprite;

    bool isShooting = false;

    sf::Clock shootingClock;

    float velocityY = 0.f;

    sf::FloatRect previousBounds;
};
