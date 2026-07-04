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
    sf::Text startText;
    sf::Text exitText;

    sf::Text highScoreText;
};