#include "ScoreManager.hpp"

void ScoreManager::add(float distance)
{
    score += static_cast<int>(distance);
}

int ScoreManager::getScore() const
{
    return score;
}

void ScoreManager::reset()
{
    score = 0;
}
