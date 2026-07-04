#include "Core/HighScoreManager.hpp"

#include <fstream>

#include "Core/Config.hpp"

HighScoreManager::HighScoreManager()
    : highScore(0)
{
    load();
}

int HighScoreManager::getHighScore() const
{
    return highScore;
}

void HighScoreManager::update(int score)
{
    if (score > highScore)
    {
        highScore = score;

        save();
    }
}

void HighScoreManager::load()
{
    std::ifstream file(Config::Save::HighScoreFile);

    if (!file.is_open())
    {
        highScore = 0;
        return;
    }

    file >> highScore;

    if (file.fail())
    {
        highScore = 0;
    }
}

void HighScoreManager::save() const
{
    std::ofstream file(Config::Save::HighScoreFile);

    if (!file.is_open())
    {
        return;
    }

    file << highScore;
}

