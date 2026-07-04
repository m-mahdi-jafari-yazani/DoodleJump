#include "Core/ResourceManager.hpp"

#include <stdexcept>

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

const sf::Texture& ResourceManager::getTexture(
    const std::string& filePath)
{
    auto it = textures.find(filePath);

    if (it != textures.end())
    {
        return *it->second;
    }

    auto texture = std::make_unique<sf::Texture>();

    if (!texture->loadFromFile(filePath))
    {
        throw std::runtime_error(
            "Cannot load texture: " + filePath
        );
    }

    const sf::Texture& textureReference = *texture;

    textures[filePath] = std::move(texture);

    return textureReference;
}

const sf::Font& ResourceManager::getFont(
    const std::string& filePath)
{
    auto it = fonts.find(filePath);

    if (it != fonts.end())
    {
        return *it->second;
    }

    auto font = std::make_unique<sf::Font>();

    if (!font->loadFromFile(filePath))
    {
        throw std::runtime_error(
            "Cannot load font: " + filePath
        );
    }

    const sf::Font& fontReference = *font;

    fonts[filePath] = std::move(font);

    return fontReference;
}

