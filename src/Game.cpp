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
    window.setFramerateLimit(
        Config::Window::FrameRateLimit
    );

    backgroundSprite.setTexture(
        ResourceManager::getInstance().getTexture(
            Config::Assets::Background
        )
    );

    auto& resources =
        ResourceManager::getInstance();

    resources.loadSound(
        "jump",
        Config::Assets::Sounds::JumpingSound
    );

    resources.loadSound(
        "lose",
        Config::Assets::Sounds::LoosingSound
    );

    resources.loadSound(
        "shoot",
        Config::Assets::Sounds::ShootingSound
    );

    settingsMenu.setDifficultyManager(
        &difficultyManager
    );

    settingsMenu.updateDifficultyText();

    monsterManager.setDifficulty(
        difficultyManager.getDifficulty()
    );

    platformManager.setDifficulty(
        difficultyManager.getDifficulty()
    );

    monsterManager.respawnMonsters(
        platformManager.getPlatformEntries()
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
            
            case GameState::Settings:
                handleSettingsInput(event);
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

    bulletManager.update(deltaTime);

    collisionManager.handleBulletMonsters(
        bulletManager.getBullets(),
        monsterManager.getMonsters()
    );

    collisionManager.handlePlayerPlatforms(
        player,
        platformManager.getPlatformEntries(),
        audio
    );

    collisionManager.handlePlayerSprings(
        player,
        platformManager.getPlatformEntries()
    );

    if (
        collisionManager.handlePlayerBlackHoles(
            player,
            blackHoleManager.getBlackHoles()
        )
    )
    {
        audio.stopMusic();

        audio.play("lose");

        highScoreManager.update(
            scoreManager.getScore()
        );

        gameStateManager.gameOver();

        return;
    }

    if (
        collisionManager.handlePlayerMonsters(
            player,
            monsterManager.getMonsters()
        )
    )
    {
        audio.stopMusic();

        audio.play("lose");

        highScoreManager.update(
            scoreManager.getScore()
        );

        gameStateManager.gameOver();

        return;
    }

    platformManager.update(deltaTime);

    monsterManager.update(deltaTime);

    if (difficultyManager.isBlackHoleEnabled())
    {
        blackHoleManager.update(deltaTime);
    }
    else
    {
        blackHoleManager.clear();
    }

    monsterManager.removeDeadMonsters();

    monsterManager.respawnMonsters(
        platformManager.getPlatformEntries()
    );

    const float cameraOffset = camera.update(player);

    platformManager.moveAll(cameraOffset);

    monsterManager.moveAll(cameraOffset);

    blackHoleManager.moveAll(cameraOffset);

    scoreManager.add(cameraOffset);

    if (player.getPosition().y > Config::Window::Height)
    {
        audio.stopMusic();

        audio.play("lose");

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
    else if (gameStateManager.isSettings())
    {
        renderSettings();
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
    if (!audio.isMusicPlaying())
    {
        audio.playMusic(
            Config::Assets::Sounds::MainMenuSound
        );
    }

    mainMenu.setHighScore(highScoreManager.getHighScore());

    window.draw(backgroundSprite);

    mainMenu.draw(window);
}

void Game::renderSettings()
{
    window.draw(backgroundSprite);

    settingsMenu.draw(window);
}

void Game::renderRunning()
{
    window.draw(backgroundSprite);

    platformManager.draw(window);

    monsterManager.draw(window);

    if (difficultyManager.isBlackHoleEnabled())
    {
        blackHoleManager.draw(window);
    }

    bulletManager.draw(window);

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

    monsterManager.clear();

    blackHoleManager.clear();

    bulletManager.clear();

    monsterManager.respawnMonsters(
        platformManager.getPlatformEntries()
    );

    scoreManager.reset();

    scoreManager.reset();
}

void Game::handleMenuInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Enter)
    {
        audio.stopMusic();

        resetGame();

        gameStateManager.startGame();
    }

    if (event.key.code == sf::Keyboard::S)
    {
        gameStateManager.showSettings();
    }

    if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
}

void Game::handleSettingsInput(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }

    float volume =
        audio.getMusicVolume();

    if (event.key.code == sf::Keyboard::Left)
    {
        volume -= 5.f;
    }

    if (event.key.code == sf::Keyboard::Right)
    {
        volume += 5.f;
    }

    if (volume < 0.f)
    {
        volume = 0.f;
    }

    if (volume > 100.f)
    {
        volume = 100.f;
    }

    if (event.key.code == sf::Keyboard::Down)
    {
        difficultyManager.previous();

        monsterManager.setDifficulty(
            difficultyManager.getDifficulty()
        );

        platformManager.setDifficulty(
            difficultyManager.getDifficulty()
        );

        settingsMenu.updateDifficultyText();
    }

    if (event.key.code == sf::Keyboard::Up)
    {
        difficultyManager.next();

        monsterManager.setDifficulty(
            difficultyManager.getDifficulty()
        );

        platformManager.setDifficulty(
            difficultyManager.getDifficulty()
        );

        settingsMenu.updateDifficultyText();
    }

    audio.setMusicVolume(volume);

    settingsMenu.setVolume(volume);

    if (event.key.code == sf::Keyboard::Escape)
    {
        gameStateManager.showMenu();
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

    if (event.key.code == sf::Keyboard::Space)
    {
        player.startShooting();

        sf::Vector2f gunPosition =
            player.getGunPosition();

        bulletManager.shoot(
            gunPosition.x,
            gunPosition.y
        );

        audio.play("shoot");
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
        audio.stopMusic();

        resetGame();

        gameStateManager.startGame();
    }

    if (event.key.code == sf::Keyboard::Escape)
    {
        gameStateManager.showMenu();
    }
}

