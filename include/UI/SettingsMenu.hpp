#pragma once

#include <SFML/Graphics.hpp>

class SettingsMenu
{
public:
    SettingsMenu();

    void draw(sf::RenderWindow& window);

private:
    sf::Text title;
    sf::Text volumeText;
    sf::Text difficultyText;
    sf::Font font;
};