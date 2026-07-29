#pragma once

#include <SFML/Graphics.hpp>
#include "Core/HighScoreManager.hpp"
#include "Core/Difficulty.hpp"

class ScoreManager;

class HUD
{
public:
    HUD();

    void draw(
        sf::RenderWindow& window,
        const ScoreManager& scoreManager,
        const HighScoreManager& highScoreManager,
        Difficulty difficulty
    );

private:
    sf::Text scoreText;
    sf::Text highScoreText;
};