#include "UI/GameOver.hpp"

#include <string>

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"
#include "Core/HighScoreManager.hpp"
#include "UI/UIHelper.hpp"

GameOver::GameOver()
{
    const sf::Font& font =
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        );

    //---------------- Title ----------------

    title.setFont(font);
    title.setString(Config::UI::GameOverPage::TitlePrompt);
    title.setCharacterSize(Config::UI::GameOverPage::TitleSize);
    title.setFillColor(Config::UI::GameOverPage::TitleColor);

    UIHelper::centerText(
        title,
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::TitleY
    );

    //---------------- Score ----------------

    scoreText.setFont(font);
    scoreText.setCharacterSize(Config::UI::GameOverPage::ScoreSize);
    scoreText.setFillColor(Config::UI::GameOverPage::ScoreColor);

    scoreText.setPosition(
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::ScoreY
    );

    //---------------- High Score ----------------

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(Config::UI::GameOverPage::HighScoreSize);
    highScoreText.setFillColor(Config::UI::GameOverPage::HighScoreColor);

    scoreText.setPosition(
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::HighScoreY
    );

    //---------------- Restart ----------------

    restartText.setFont(font);
    restartText.setString(Config::UI::GameOverPage::RestartPrompt);
    restartText.setCharacterSize(Config::UI::GameOverPage::RestartSize);
    restartText.setFillColor(Config::UI::GameOverPage::RestartColor);

    UIHelper::centerText(
        restartText,
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::RestartY
    );
    //---------------- Menu ----------------

    menuText.setFont(font);
    menuText.setString(Config::UI::GameOverPage::MenuPrompt);
    menuText.setCharacterSize(Config::UI::GameOverPage::MenuSize);
    menuText.setFillColor(Config::UI::GameOverPage::MenuColor);

    UIHelper::centerText(
        menuText,
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::MenuY
    );
}

void GameOver::setScores(int score, int highScore)
{
    scoreText.setString(
        Config::UI::GameOverPage::ScorePrompt +
        std::to_string(score)
    );

    UIHelper::centerText(
        scoreText,
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::ScoreY
    );

    

    highScoreText.setString(
        Config::UI::GameOverPage::HighScorePrompt +
        std::to_string(highScore)
    );

    UIHelper::centerText(
        highScoreText,
        Config::Window::Width / 2.f,
        Config::UI::GameOverPage::HighScoreY
    );
}

void GameOver::draw(sf::RenderWindow& window) const
{
    window.draw(title);
    window.draw(scoreText);
    window.draw(restartText);
    window.draw(menuText);
    window.draw(highScoreText);
}

