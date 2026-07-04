#pragma once

#include "Core/GameState.hpp"

class GameStateManager
{
public:
    GameStateManager();

    GameState getState() const;

    void setState(GameState state);

    void startGame();
    void showMenu();
    void pause();
    void resume();
    void gameOver();

    bool isRunning() const;
    bool isPaused() const;
    bool isGameOver() const;
    bool isMenu() const;

private:
    GameState currentState;
};