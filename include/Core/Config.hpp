#pragma once

#include <SFML/Graphics/Color.hpp>

namespace Config
{    
    namespace Assets
    {
        constexpr const char* RightDoodle =
            "../assets/right_doodle.png";

        constexpr const char* LeftDoodle =
            "../assets/left_doodle.png";

        constexpr const char* Background =
            "../assets/background.png";

        constexpr const char* NormalPlatform =
            "../assets/normal_platform.png";

        constexpr const char* MovingPlatform =
            "../assets/moving_platform.png";

        constexpr const char* BrokenPlatform =
            "../assets/broken_platform.png";

        constexpr const char* Spring =
            "../assets/spring_sprite.png";
    }

    namespace Fonts
    {
        constexpr const char* Default = "../fonts/ariblk.ttf";
    }

    namespace Window
    {
        constexpr const char* Title = "Doodle Jump";

        constexpr unsigned int Width = 800;
        constexpr unsigned int Height = 600;

        constexpr unsigned int FrameRateLimit = 60;
    }

    namespace Player
    {
        constexpr float StartX = 400.f;
        constexpr float StartY = 500.f;

        constexpr float MoveSpeed = 300.f;
        constexpr float Gravity = 900.f;
        constexpr float JumpForce = 650.f;
    }

    namespace Platform
    {
        constexpr float InitialSupportOffset = 50.f;
        constexpr float InitialY = 550.f;

        constexpr int Count = 15;

        constexpr float Spacing = 70.f;

        constexpr float SpawnY = -50.f;
        constexpr float DestroyY = 650.f;

        constexpr float MinX = 40.f;
        constexpr float MaxX = 700.f;

        constexpr float MinHorizontalDistance = 70.f;
        constexpr float MinVerticalCheckDistance = 60.f;

        constexpr int MaxSpawnAttempts = 20;

        constexpr float MinVerticalSpacing = 70.f;
        constexpr float MaxVerticalSpacing = 110.f;
    }

    namespace MovingPlatform
    {
        constexpr float Speed = 100.f;

        constexpr int SpawnChance = 20;
    }

    namespace BrokenPlatform
    {
        constexpr float Gravity = 900.f;

        constexpr int SpawnChance = 10;
    }

    namespace Spring
    {
        constexpr float OffsetY = -35.f;
        constexpr int JumpVelocity = -900;
        constexpr int SpawnChance = 10;
    }

    namespace Camera
    {
        constexpr float ThresholdY = 300.f;
    }

    namespace UI
    {
        namespace MainMenuPage
        {
            constexpr const char* GameTitle = "DOODLE JUMP";
            constexpr unsigned int TitleSize = 80;
            const sf::Color TitleColor = sf::Color::Green;
            constexpr float TitleY = 150.f;

            constexpr const char* HighScorePrompt = "High Score: 0";
            constexpr unsigned int HighScoreSize = 30;
            const sf::Color HighScoreColor = sf::Color::Magenta;
            constexpr float HighScoreY = 250.f;

            constexpr const char* StartPrompt = "Press ENTER to Start";
            constexpr unsigned int StartSize = 40;
            const sf::Color StartColor = sf::Color::Blue;
            constexpr float StartY = 320.f;

            constexpr const char* ExitPrompt = "Press ESC to Exit";
            constexpr unsigned int ExitSize = 40;
            const sf::Color ExitColor = sf::Color::Cyan;
            constexpr float ExitY = 380.f;
        }
        namespace PlayingPage
        {
            constexpr const char* ScorePrompt = "Score : ";
            constexpr unsigned int ScoreSize = 25;
            const sf::Color ScoreColor = sf::Color::Black;
            constexpr float ScoreX = 20;
            constexpr float ScoreY = 20;

            constexpr const char* HighScorePrompt = "High Score : ";
            constexpr unsigned int HighScoreSize = 15;
            const sf::Color HighScoreColor = sf::Color::Magenta;
            constexpr float HighScoreX = 20;
            constexpr float HighScoreY = 50;

        }
        namespace GameOverPage
        {
            constexpr const char* TitlePrompt = "GAME OVER";
            constexpr unsigned int TitleSize = 80;
            const sf::Color TitleColor = sf::Color::Red;
            constexpr float TitleY = 140;

            constexpr const char* ScorePrompt = "Score : ";
            constexpr unsigned int ScoreSize = 40;
            const sf::Color ScoreColor = sf::Color::Black;
            constexpr float ScoreY = 250.f;

            constexpr const char* HighScorePrompt = "High Score : ";
            constexpr unsigned int HighScoreSize = 20;
            const sf::Color HighScoreColor = sf::Color::Magenta ;
            constexpr float HighScoreY = 290.f;

            constexpr const char* RestartPrompt = "Press ENTER to Restart";
            constexpr unsigned int RestartSize = 30;
            const sf::Color RestartColor = sf::Color::Blue;
            constexpr float RestartY = 360;

            constexpr const char* MenuPrompt = "Press ESC to Menu";
            constexpr unsigned int MenuSize = 30;
            const sf::Color MenuColor = sf::Color::Cyan;
            constexpr float MenuY = 420;

        }
    }

    namespace Save
    {
        inline constexpr const char* HighScoreFile = "highscore.txt";
    }
}