#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Core/ResourceCache.hpp"

class ResourceManager
{
public:
    static ResourceManager& getInstance();

    const sf::Texture& getTexture(const std::string& filePath);

    const sf::Font& getFont(const std::string& filePath);

    void loadSound(const std::string& id, const std::string& filename);

    const sf::SoundBuffer& getSound(const std::string& id) const;

private:
    ResourceManager() = default;

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(
        const ResourceManager&
    ) = delete;

private:
    ResourceCache<sf::Texture> textures;

    ResourceCache<sf::Font> fonts;

    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
};