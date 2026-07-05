#pragma once


#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Platform/Platform.hpp"
#include "Platform/PlatformManager.hpp"
#include "CollisionManager.hpp"
#include "Camera.hpp"
#include "ScoreManager.hpp"
#include "UI/HUD.hpp"
#include "Core/GameStateManager.hpp"
#include "UI/MainMenu.hpp"
#include "UI/GameOver.hpp"
#include "Core/HighScoreManager.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();

    void update(float deltaTime);
    void updateRunning(float deltaTime);

    void render();
    void renderMenu();
    void renderRunning();
    void renderGameOver();

    void pause();
    void resume();

    void resetGame();

    void handleMenuInput(const sf::Event& event);
    void handleRunningInput(const sf::Event& event);
    void handlePausedInput(const sf::Event& event);
    void handleGameOverInput(const sf::Event& event);

private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Sprite backgroundSprite;
    Player player;
    PlatformManager platformManager;
    CollisionManager collisionManager;
    Camera camera;
    ScoreManager scoreManager;
    HUD hud;
    GameStateManager gameStateManager;
    MainMenu mainMenu;
    GameOver gameOver;
    HighScoreManager highScoreManager;
};
