#pragma once

#include <SFML/Graphics.hpp>
#include "Core/DifficultyManager.hpp"

class SettingsMenu
{
public:
    SettingsMenu();

    void draw(sf::RenderWindow& window) const;

    void setVolume(float volume);

    float getVolume() const;

    void setDifficultyManager(DifficultyManager* manager);

    void updateDifficultyText();

private:
    sf::Text title;

    sf::Text volumeText;

    sf::Text instructionText;

    sf::Text backText;

    float volume = 100.f;

    sf::Text difficultyText;

    DifficultyManager* difficultyManager = nullptr;
};