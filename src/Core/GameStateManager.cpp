#include "Core/GameStateManager.hpp"

GameStateManager::GameStateManager()
    : currentState(GameState::Menu)
{
}

GameState GameStateManager::getState() const
{
    return currentState;
}

void GameStateManager::setState(GameState state)
{
    currentState = state;
}

void GameStateManager::startGame()
{
    currentState = GameState::Running;
}
void GameStateManager::showMenu()
{
    currentState = GameState::Menu;
}
void GameStateManager::pause()
{
    currentState = GameState::Paused;
}
void GameStateManager::resume()
{
    currentState = GameState::Running;
}
void GameStateManager::gameOver()
{
    currentState = GameState::GameOver;
}

bool GameStateManager::isRunning() const
{
    return currentState == GameState::Running;
}
bool GameStateManager::isPaused() const
{
    return currentState == GameState::Paused;
}
bool GameStateManager::isGameOver() const
{
    return currentState == GameState::GameOver;
}
bool GameStateManager::isMenu() const
{
    return currentState == GameState::Menu;
}

