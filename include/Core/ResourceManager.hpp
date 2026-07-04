#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    static ResourceManager& getInstance();

    const sf::Texture& getTexture(const std::string& filePath);
    const sf::Font& getFont(const std::string& filePath);

private:
    ResourceManager() = default;

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

private:
    std::unordered_map<
        std::string,
        std::unique_ptr<sf::Texture>
    > textures;

    std::unordered_map<
        std::string,
        std::unique_ptr<sf::Font>
    > fonts;
};