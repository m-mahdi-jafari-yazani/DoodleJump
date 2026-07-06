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

