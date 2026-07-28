#include "Core/DifficultyManager.hpp"

DifficultyManager::DifficultyManager()
    :
    difficulty(Difficulty::Medium)
{
}

void DifficultyManager::next()
{
    switch (difficulty)
    {
        case Difficulty::Easy:
            difficulty = Difficulty::Medium;
            break;

        case Difficulty::Medium:
            difficulty = Difficulty::Hard;
            break;

        case Difficulty::Hard:
            break;
    }
}

void DifficultyManager::previous()
{
    switch (difficulty)
    {
        case Difficulty::Hard:
            difficulty = Difficulty::Medium;
            break;

        case Difficulty::Medium:
            difficulty = Difficulty::Easy;
            break;

        case Difficulty::Easy:
            break;
    }
}

Difficulty DifficultyManager::getDifficulty() const
{
    return difficulty;
}

const char* DifficultyManager::getDifficultyName() const
{
    switch (difficulty)
    {
        case Difficulty::Easy:
            return "Easy";

        case Difficulty::Medium:
            return "Medium";

        case Difficulty::Hard:
            return "Hard";
    }

    return "Medium";
}
