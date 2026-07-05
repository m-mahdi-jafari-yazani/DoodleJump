#include "Game.hpp"

#include <stdexcept>

#include "Core/Config.hpp"
#include "Core/ResourceManager.hpp"

Game::Game()
    : window(
          sf::VideoMode(
              Config::Window::Width,
              Config::Window::Height
          ),
          Config::Window::Title
      )
{
    window.setFramerateLimit(Config::Window::FrameRateLimit);

    backgroundSprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::Background
        )
    );
}

void Game::run()
{
    while (window.isOpen())
    {
        const float deltaTime = clock.restart().asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        switch (gameStateManager.getState())
        {
            case GameState::Menu:
                handleMenuInput(event);
                break;

            case GameState::Running:
                handleRunningInput(event);
                break;

            case GameState::Paused:
                handlePausedInput(event);
                break;

            case GameState::GameOver:
                handleGameOverInput(event);
                break;
        }
    }
}

void Game::update(float deltaTime)
{
    if (!gameStateManager.isRunning())
    {
        return;
    }

    updateRunning(deltaTime);
}

void Game::updateRunning(float deltaTime)
{
    player.update(deltaTime, window.getSize().x);

    collisionManager.handlePlayerPlatforms(
        player,
        platformManager.getPlatformEntries()
    );

    collisionManager.handlePlayerSprings(
        player,
        platformManager.getPlatformEntries()
    );

    platformManager.update(deltaTime);

    const float cameraOffset = camera.update(player);

    platformManager.moveAll(cameraOffset);

    scoreManager.add(cameraOffset);

    if (player.getPosition().y > Config::Window::Height)
    {
        highScoreManager.update(scoreManager.getScore());
        gameStateManager.gameOver();
    }
}

void Game::render()
{
    window.clear();

    if (gameStateManager.isMenu())
    {
        renderMenu();
    }
    else if (gameStateManager.isGameOver())
    {
        renderGameOver();
    }
    else
    {
        renderRunning();
    }

    window.display();
}

void Game::renderMenu()
{
    mainMenu.setHighScore(highScoreManager.getHighScore());

    window.draw(backgroundSprite);

    mainMenu.draw(window);
}

void Game::renderRunning()
{
    window.draw(backgroundSprite);

    platformManager.draw(window);

    player.draw(window);

    hud.draw(
        window,
        scoreManager,
        highScoreManager
    );
}

void Game::renderGameOver()
{
    gameOver.setScores(
        scoreManager.getScore(),
        highScoreManager.getHighScore()
    );

    window.draw(backgroundSprite);

    gameOver.draw(window);
}

void Game::pause()
{
    gameStateManager.pause();
}

void Game::resume()
{
    gameStateManager.resume();
}

void Game::resetGame()
{
    player.reset();

    platformManager.reset();

    scoreManager.reset();
}

void Game::handleMenuInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Enter)
    {
        resetGame();

        gameStateManager.startGame();
    }

    if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
}

void Game::handleRunningInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Escape)
    {
        pause();
    }
}

void Game::handlePausedInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Escape)
    {
        resume();
    }
}

void Game::handleGameOverInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Enter)
    {
        resetGame();

        gameStateManager.startGame();
    }

    if (event.key.code == sf::Keyboard::Escape)
    {
        gameStateManager.showMenu();
    }
}

