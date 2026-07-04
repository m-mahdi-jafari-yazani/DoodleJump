#pragma once

#include <SFML/Graphics.hpp>

class GameOver
{
public:
    GameOver();

    void setScores(int score, int highScore);

    void draw(sf::RenderWindow& window) const;

private:
    sf::Text title;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::Text restartText;
    sf::Text menuText;
};