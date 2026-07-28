#pragma once

#include <SFML/Graphics.hpp>

#include "Physics/PhysicsState.hpp"

class Monster
{
public:
    Monster();

    virtual ~Monster() = default;

    virtual void update(float deltaTime);

    virtual void draw(sf::RenderWindow& window) const;

    void setPosition(float x, float y);

    sf::Vector2f getPosition() const;

    sf::FloatRect getBounds() const;

    void move(float dx, float dy);

    void moveVertical(float dy);

    bool isAlive() const;

    void kill();

    void damage(int amount);

    int getHealth() const;

    void setHealth(int health);

    void setTexture(const sf::Texture& texture);

    void setScale(float x, float y);

    void setDirection(int direction);

    int getDirection() const;

    bool canPlayerBounce(const PhysicsState& physicsState) const;

    void setSpeed(float value);

protected:
    sf::Sprite sprite;

    float speed;

    int direction;

    int health;

    bool alive;
};