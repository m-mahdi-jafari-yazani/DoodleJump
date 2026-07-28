#include "UI/SettingsMenu.hpp"

#include <string>

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"
#include "UI/UIHelper.hpp"

SettingsMenu::SettingsMenu()
{
    const sf::Font& font =
        ResourceManager::getInstance().getFont(
            Config::Fonts::Default
        );

    // ---------- Title ----------

    title.setFont(font);
    title.setString(
        Config::UI::SettingsPage::Title
    );
    title.setCharacterSize(
        Config::UI::SettingsPage::TitleSize
    );
    title.setFillColor(
        Config::UI::SettingsPage::TitleColor
    );

    UIHelper::centerText(
        title,
        Config::Window::Width / 2.f,
        Config::UI::SettingsPage::TitleY
    );

    // ---------- Volume ----------

    volumeText.setFont(font);
    volumeText.setCharacterSize(
        Config::UI::SettingsPage::VolumeSize
    );
    volumeText.setFillColor(
        Config::UI::SettingsPage::VolumeColor
    );

    setVolume(100.f);

    // ---------- Instruction ----------

    instructionText.setFont(font);
    instructionText.setString(
        Config::UI::SettingsPage::Instruction
    );
    instructionText.setCharacterSize(
        Config::UI::SettingsPage::InstructionSize
    );
    instructionText.setFillColor(
        Config::UI::SettingsPage::InstructionColor
    );

    UIHelper::centerText(
        instructionText,
        Config::Window::Width / 2.f,
        Config::UI::SettingsPage::InstructionY
    );

    // ---------- Back ----------

    backText.setFont(font);
    backText.setString(
        Config::UI::SettingsPage::BackPrompt
    );
    backText.setCharacterSize(
        Config::UI::SettingsPage::BackSize
    );
    backText.setFillColor(
        Config::UI::SettingsPage::BackColor
    );

    UIHelper::centerText(
        backText,
        Config::Window::Width / 2.f,
        Config::UI::SettingsPage::BackY
    );
}

void SettingsMenu::draw(
    sf::RenderWindow& window
) const
{
    window.draw(title);
    window.draw(volumeText);
    window.draw(instructionText);
    window.draw(backText);
}

void SettingsMenu::setVolume(
    float value
)
{
    volume = value;

    volumeText.setString(
        std::string(
            Config::UI::SettingsPage::VolumePrefix
        ) +
        std::to_string(
            static_cast<int>(volume)
        )
    );

    UIHelper::centerText(
        volumeText,
        Config::Window::Width / 2.f,
        Config::UI::SettingsPage::VolumeY
    );
}

float SettingsMenu::getVolume() const
{
    return volume;
}
