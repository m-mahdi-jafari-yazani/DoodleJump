#include "UI/HUD.hpp"

#include <string>

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"
#include "ScoreManager.hpp"

HUD::HUD()
{
    scoreText.setFont(
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        )
    );
    scoreText.setCharacterSize(Config::UI::PlayingPage::ScoreSize);
    scoreText.setFillColor(Config::UI::PlayingPage::ScoreColor);
    scoreText.setPosition(Config::UI::PlayingPage::ScoreX, Config::UI::PlayingPage::ScoreY);



    highScoreText.setFont(
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        )
    );
    highScoreText.setCharacterSize(Config::UI::PlayingPage::HighScoreSize);
    highScoreText.setFillColor(Config::UI::PlayingPage::HighScoreColor);
    highScoreText.setPosition(Config::UI::PlayingPage::HighScoreX, Config::UI::PlayingPage::HighScoreY);
}

void HUD::draw(
    sf::RenderWindow& window,
    const ScoreManager& scoreManager,
    const HighScoreManager& highScoreManager)
{
    scoreText.setString(
        Config::UI::PlayingPage::ScorePrompt +
        std::to_string(scoreManager.getScore())
    );

    highScoreText.setString(
        Config::UI::PlayingPage::HighScorePrompt +
        std::to_string(highScoreManager.getHighScore())
    );

    window.draw(scoreText);
    window.draw(highScoreText);
}

