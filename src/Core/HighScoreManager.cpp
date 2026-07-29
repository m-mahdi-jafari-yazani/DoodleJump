#include "Core/HighScoreManager.hpp"

#include <fstream>
#include <array>

#include "Core/Config.hpp"

namespace
{
    std::size_t toIndex(
        Difficulty difficulty
    )
    {
        return static_cast<std::size_t>(
            difficulty
        );
    }
}

HighScoreManager::HighScoreManager()
{
    highScores.fill(0);

    load();
}

int HighScoreManager::getHighScore(
    Difficulty difficulty
) const
{
    return highScores[
        toIndex(difficulty)
    ];
}

void HighScoreManager::update(
    Difficulty difficulty,
    int score
)
{
    std::size_t index =
        toIndex(difficulty);

    if (score > highScores[index])
    {
        highScores[index] = score;

        save();
    }
}

void HighScoreManager::load()
{
    std::ifstream file(
        Config::Save::HighScoreFile
    );

    if (!file.is_open())
    {
        highScores.fill(0);
        return;
    }

    for (int& score : highScores)
    {
        if (!(file >> score))
        {
            score = 0;
        }
    }
}

void HighScoreManager::save() const
{
    std::ofstream file(
        Config::Save::HighScoreFile
    );

    if (!file.is_open())
    {
        return;
    }

    for (int score : highScores)
    {
        file
            << score
            << '\n';
    }
}

