#pragma once

#include <array>

#include "Core/Difficulty.hpp"

class HighScoreManager
{
public:
    HighScoreManager();

    int getHighScore(Difficulty difficulty) const;

    void update(Difficulty difficulty,int score);

private:
    void load();

    void save() const;

private:
    std::array<int, 3> highScores{};
};