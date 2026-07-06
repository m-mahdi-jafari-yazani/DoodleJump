#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Core/ResourceCache.hpp"

class ResourceManager
{
public:
    static ResourceManager& getInstance();

    const sf::Texture& getTexture(
        const std::string& filePath
    );

    const sf::Font& getFont(
        const std::string& filePath
    );

private:
    ResourceManager() = default;

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(
        const ResourceManager&
    ) = delete;

private:
    ResourceCache<sf::Texture> textures;

    ResourceCache<sf::Font> fonts;
};