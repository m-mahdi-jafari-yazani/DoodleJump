#pragma once

#include <SFML/Graphics.hpp>

class SettingsMenu
{
public:
    SettingsMenu();

    void draw(sf::RenderWindow& window) const;

    void setVolume(float volume);

    float getVolume() const;

private:
    sf::Text title;

    sf::Text volumeText;

    sf::Text instructionText;

    sf::Text backText;

    float volume = 100.f;
};