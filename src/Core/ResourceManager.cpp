#include "Core/ResourceManager.hpp"

ResourceManager&
ResourceManager::getInstance()
{
    static ResourceManager instance;

    return instance;
}

const sf::Texture&
ResourceManager::getTexture(
    const std::string& filePath
)
{
    return textures.get(filePath);
}

const sf::Font&
ResourceManager::getFont(
    const std::string& filePath
)
{
    return fonts.get(filePath);
}

void ResourceManager::loadSound(const std::string& id,
                                const std::string& filename)
{
    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile(filename))
        throw std::runtime_error("Failed to load sound: " + filename);

    soundBuffers.emplace(id, std::move(buffer));
}

const sf::SoundBuffer&
ResourceManager::getSound(const std::string& id) const
{
    return soundBuffers.at(id);
}

