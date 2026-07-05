#pragma once

#include <SFML/Graphics.hpp>

#include "Physics/PhysicsState.hpp"

class Player;

class Platform
{
public:
    Platform(float x, float y);
    virtual ~Platform() = default;

    virtual void update(float deltaTime) = 0;

    virtual void draw(sf::RenderWindow& window) const;

    void move(float dx, float dy);

    virtual bool canJumpOn(const PhysicsState& physicsState) const;

    virtual void onPlayerLanded(Player& player);

    sf::FloatRect getBounds() const;

    sf::Vector2f getPosition() const;

    void setPosition(float x, float y);

    float getTop() const;

    float getWidth() const;

    virtual bool canHaveSpring() const;

protected:
    sf::Sprite sprite;
};