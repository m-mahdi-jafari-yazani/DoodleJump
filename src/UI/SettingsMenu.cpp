#include "UI/SettingsMenu.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

SettingsMenu::SettingsMenu()
{
    font =
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        );

    title.setFont(font);
    title.setCharacterSize(60);
    title.setString("SETTINGS");
    title.setFillColor(sf::Color::Black);
    title.setPosition(220.f, 80.f);

    volumeText.setFont(font);
    volumeText.setCharacterSize(35);
    volumeText.setString("Volume");
    volumeText.setFillColor(sf::Color::Blue);
    volumeText.setPosition(250.f, 220.f);

    difficultyText.setFont(font);
    difficultyText.setCharacterSize(35);
    difficultyText.setString("Difficulty");
    difficultyText.setFillColor(sf::Color::Blue);
    difficultyText.setPosition(250.f, 320.f);
}

void SettingsMenu::draw(sf::RenderWindow& window)
{
    window.draw(title);
    window.draw(volumeText);
    window.draw(difficultyText);
}