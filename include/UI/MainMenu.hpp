#pragma once

#include <SFML/Graphics.hpp>

class MainMenu
{
public:
    MainMenu();

    void draw(sf::RenderWindow& window) const;

    void setHighScore(int score);

private:
    sf::Text title;

    sf::Text highScoreText;

    sf::Text startText;

    sf::Text settingsText;

    sf::Text exitText;
};