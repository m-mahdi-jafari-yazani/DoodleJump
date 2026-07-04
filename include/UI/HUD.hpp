#pragma once

#include <SFML/Graphics.hpp>
#include "Core/HighScoreManager.hpp"

class ScoreManager;

class HUD
{
public:
    HUD();

    void draw(sf::RenderWindow& window,
          const ScoreManager& scoreManager,
          const HighScoreManager& highScoreManager);

private:
    sf::Text scoreText;
    sf::Text highScoreText;
};