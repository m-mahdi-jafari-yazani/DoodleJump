#include "UI/MainMenu.hpp"

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"
#include "UI/UIHelper.hpp"

MainMenu::MainMenu()
{
    const sf::Font& font =
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        );

    // ---------- Title ----------

    title.setFont(font);
    title.setString(Config::UI::MainMenuPage::GameTitle);
    title.setCharacterSize(Config::UI::MainMenuPage::TitleSize);
    title.setFillColor(Config::UI::MainMenuPage::TitleColor);

    UIHelper::centerText(
        title,
        Config::Window::Width / 2.f,
        Config::UI::MainMenuPage::TitleY
    );

    // ---------- High Score ----------

    highScoreText.setFont(font);
    highScoreText.setString(Config::UI::MainMenuPage::HighScorePrompt);
    highScoreText.setCharacterSize(Config::UI::MainMenuPage::HighScoreSize);
    highScoreText.setFillColor(Config::UI::MainMenuPage::HighScoreColor);

    UIHelper::centerText(
        highScoreText,
        Config::Window::Width / 2.f,
        Config::UI::MainMenuPage::HighScoreY
    );

    // ---------- Start ----------

    startText.setFont(font);
    startText.setString(Config::UI::MainMenuPage::StartPrompt);
    startText.setCharacterSize(Config::UI::MainMenuPage::StartSize);
    startText.setFillColor(Config::UI::MainMenuPage::StartColor);

    UIHelper::centerText(
        startText,
        Config::Window::Width / 2.f,
        Config::UI::MainMenuPage::StartY
    );

    // ---------- Exit ----------

    exitText.setFont(font);
    exitText.setString(Config::UI::MainMenuPage::ExitPrompt);
    exitText.setCharacterSize(Config::UI::MainMenuPage::ExitSize);
    exitText.setFillColor(Config::UI::MainMenuPage::ExitColor);

    UIHelper::centerText(
        exitText,
        Config::Window::Width / 2.f,
        Config::UI::MainMenuPage::ExitY
    );
}

void MainMenu::draw(sf::RenderWindow& window) const
{
    window.draw(title);
    window.draw(highScoreText);
    window.draw(startText);
    window.draw(exitText);
}

void MainMenu::setHighScore(int score)
{
    highScoreText.setString(
        "High Score: " +
        std::to_string(score)
    );

    UIHelper::centerText(
        highScoreText,
        Config::Window::Width / 2.f,
        Config::UI::MainMenuPage::HighScoreY
    );
}

