#pragma once

#include <memory>

#include "Platform/Platform.hpp"
#include "Item/Spring.hpp"

class PlatformEntry
{
public:
    PlatformEntry(
        std::unique_ptr<Platform> platform,
        std::unique_ptr<Spring> spring = nullptr
    );

    Platform& getPlatform();
    const Platform& getPlatform() const;

    Spring& getSpring();
    const Spring& getSpring() const;

    bool hasSpring() const;

    void syncSpring();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    void move(float dy);

    bool isOffScreen() const;

    bool canPlayerJumpOn(const PhysicsState& physicsState) const;

    void playerLanded(Player& player);

    bool checkSpringCollision(Player& player);

private:
    std::unique_ptr<Platform> platform;

    std::unique_ptr<Spring> spring;
};
